function input() {
    var matrix = [readline(), readline(), readline()];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matrix[i][j] == "~") {
                matrix[i][j] = 0;
            }
            else {
                matrix[i][j] = 1;
            }
        }
    }
    const buttons = readline();
    return matrix, buttons;
}

function reverse(button: int):int {
    return (button+1)%2;
}


function main() {
    var matrix, buttons = input();
    
    var answer = null;

    console.log(answer);
}
