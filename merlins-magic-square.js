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
function reverse_row(row: array, size: int): array{
    for (i = 0; i <= size; i++) {
        row[i] = reverse(button=row[i]);
    }
    return row;
}

// reverse a square (2 x 2 buttons)
function reverse_square(square: array): array{
    for (i = 0; i < 2; i++) {
        square[i] = reverse_row(row=square[i], size=2);
    }
    return square;
}

function transform(matrix: array, button:char):array {
    let button = parseInt(button);

    // center
    if (button == 5) {
        matrix[1][1] = reverse(matrix[1][1]);
    }
    
    // corners
    else if (button in [1, 3, 7, 9]) {
        // 1 --> 00 01 10 11
        // 3 --> 01 02 11 12
        // 7 --> 01 11 20 21
        // 9 --> 11 12 21 22
    }
    
    // sides
    else if (button in [2, 4, 6, 8]) {
        // 2 --> 00 01 02
        // 4 --> 00 10 20
        // 6 --> 02 12 22
        // 8 --> 20 21 22
    }

    return matrix;
}

function main() {
    var [matrix, buttons] = input();
    
    var answer = null;

    console.log(answer);
}
