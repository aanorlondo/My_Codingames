// get inputs
function input(): array {
    var matrix = [readline(), readline(), readline()];
    const buttons = readline();
    return [matrix, buttons];
}

// reverse a position
function reverse(button: char):char {
    return button == '*' ? '~' : '*';
}

// reverse a row (3 buttons)
function reverse_row(row: array): array{
    for (i = 0; i < 2; i++) {
        row[i] = reverse(row[i]);
    }
    return row;
}

// reverse a square (2 x 2 buttons)
function reverse_square(square: array): array{
    for (i = 0; i < 2; i++) {
        square[i] = reverse_row(square[i]);
    }
    return square;
}

function transform(matrix: array, button:char):array {
    let button = parseInt(button);

    if (button == 5) {
        matrix[1][1] = reverse(matrix[1][1]);
    }
    return matrix;
    
    if (button in [1, 3, 7, 9]) {
        
    }
    
    if (button in [2, 4, 6, 8]) {

    }
    
}

function main() {
    var [matrix, buttons] = input();
    
    var answer = null;

    console.log(answer);
}
