lines = list()
elements = [[],[],[],[],[]]
win = False
for i in range(3):
    line = input()

    if line.count("O") == 2 and "." in line :
        line = "OOO"
        win = True
    lines.append(line)

    if not win :
        elements[0].append(line[0])
        elements[1].append(line[1])
        elements[2].append(line[2])
        elements[3].append(line[i])
        elements[4].append(line[3-i-1])

if not win :
    for i, col in enumerate(elements) :
        if col.count("O") == 2 and "." in col :
            index_point =col.index(".")
            i = index_point if i ==3 else i
            i = 3 - index_point - 1 if i == 4 else i
            lines[index_point] = lines[index_point][:i] + "O" + lines[index_point][i+1:]
            win = True
            break

if win :
    for line in lines :
        print(line)

else :
    print("false")
