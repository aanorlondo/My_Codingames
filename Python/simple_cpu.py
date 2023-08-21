import sys

op_len = 4
program = input()
instructions = [program[i : i + op_len] for i in range(0, len(program), op_len)]

reg = {"0": 0, "1": 0, "2": 0}

opcode = {
    "1": lambda x, y: [str(int(x, 16)), int(y, 16)],
    "20": lambda x, y: [str(int(x, 16)), reg[f"{int(x,16)}"] + reg[f"{int(y,16)}"]],
    "30": lambda x, y: [
        str(int(x, 16)),
        str(int(y, 16)),
        reg[f"{int(x,16)}"] - reg[f"{int(y,16)}"],
    ],
    "40": lambda x, y: [str(int(x, 16)), reg[f"{int(x,16)}"] | reg[f"{int(y,16)}"]],
    "50": lambda x, y: [str(int(x, 16)), reg[f"{int(x,16)}"] & reg[f"{int(y,16)}"]],
    "60": lambda x, y: [str(int(x, 16)), reg[f"{int(x,16)}"] ^ reg[f"{int(y,16)}"]],
    "7": lambda x, y: True if reg[f"{int(x,16)}"] == int(y, 16) else False,
    "8": lambda x, y: True if reg[f"{int(x,16)}"] != int(y, 16) else False,
    "90": lambda x, y: True if reg[f"{int(x,16)}"] == reg[f"{int(y,16)}"] else False,
    "A0": lambda x, y: True if reg[f"{int(x,16)}"] != reg[f"{int(y,16)}"] else False,
}

format = {"knn": lambda x: (x[1], x[2:]), "xy": lambda x: (x[2], x[3])}


print(instructions, file=sys.stderr)
print("regs", reg, file=sys.stderr)

skip = False
for i in instructions:
    print("--instruction:", i, file=sys.stderr)
    if skip:
        print("skip:", skip, file=sys.stderr)
        skip = False
        continue

    elif i == "0000":
        print("exit", file=sys.stderr)
        print(reg["0"], reg["1"], reg["2"])
        exit(0)

    elif i.startswith("1"):  # LD
        args = format["knn"](i)
        reg_index, value = opcode["1"](args[0], args[1])
        reg[reg_index] = value
        print("LOAD", value, "TO REG", reg_index, "/regs:", reg, file=sys.stderr)

    elif i.startswith("20"):  # ADD
        args = format["knn"](i)
        reg_index, SUM_decimal = opcode["20"](args[0], args[1])
        SUM_bin = bin(SUM_decimal).replace("0b", "")
        SUM_bits = len(SUM_bin)
        if SUM_bits <= 8:
            reg[reg_index] = SUM_decimal
            reg["2"] = 0
        else:
            reg[reg_index] = int("0b" + SUM_bin[SUM_bits - 8 :], 2)
            reg["2"] = 1
        print(
            "ADD RESULT",
            SUM_decimal,
            "TO REG",
            reg_index,
            "/regs:",
            reg,
            file=sys.stderr,
        )

    elif i.startswith("30"):  # SUB (x-y)
        args = format["xy"](i)
        x_index, y_index, SUB = opcode["30"](args[0], args[1])
        reg["2"] = 1 if reg[x_index] < reg[y_index] else 0
        reg[x_index] = SUB + 256 if reg[x_index] < reg[y_index] else SUB
        print("SUB REG", y_index, "FROM REG", x_index, "/regs:", reg, file=sys.stderr)

    elif i.startswith("40"):  # OR
        args = format["xy"](i)
        reg_index, OR = opcode["40"](args[0], args[1])
        reg[reg_index] = OR

    elif i.startswith("50"):  # AND
        args = format["xy"](i)
        reg_index, AND = opcode["50"](args[0], args[1])
        reg[reg_index] = AND

    elif i.startswith("60"):  # XOR
        args = format["xy"](i)
        reg_index, XOR = opcode["60"](args[0], args[1])
        reg[reg_index] = XOR

    elif i.startswith("7"):  # REG == VAL
        args = format["knn"](i)
        skip = opcode["7"](args[0], args[1])

    elif i.startswith("8"):  # REG != VAL
        args = format["knn"](i)
        skip = opcode["8"](args[0], args[1])

    elif i.startswith("90"):  # REG == REG
        args = format["xy"](i)
        skip = opcode["90"](args[0], args[1])

    elif i.startswith("A0"):  # REG != REG
        args = format["xy"](i)
        skip = opcode["A0"](args[0], args[1])
