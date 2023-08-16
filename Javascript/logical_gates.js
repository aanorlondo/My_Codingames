function to_bool(symbol) {
    return (symbol == "-") ? true : false;
}

function calculate_result(operation, input1, input2) {
    result = "";
    for (i = 0; i < input1.length; i++) {
        bool1 = to_bool(input1[i]);
        bool2 = to_bool(input2[i]);
        pos_result = null;
        switch (operation) {
            case "AND": {
                pos_result = (bool1 && bool2);
                break;
            }
            case "OR": {
                pos_result = (bool1 || bool2);
                break;
            }
            case "XOR": {
                pos_result = (bool1 ^ bool2);
                break;
            }
            case "NAND": {
                pos_result = !(bool1 && bool2);
                break;
            }
            case "NOR": {
                pos_result = !(bool1 || bool2);
                break;
            }
            case "NXOR": {
                pos_result = !(bool1 ^ bool2);
                break;
            }
        }
        pos_result ? result += "-" : result += "_";
    }
    return result;
}

const n = parseInt(readline());
const m = parseInt(readline());
var signals = {};
for (let i = 0; i < n; i++) {
    var inputs = readline().split(' ');
    signals[inputs[0]] = inputs[1];
}
for (let i = 0; i < m; i++) {
    var inputs = readline().split(' ');
    console.log(`${inputs[0]} ${calculate_result(inputs[1], signals[inputs[2]], signals[inputs[3]])}`);
}