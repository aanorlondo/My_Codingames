// define switches
let switches = {
    1: [1, 2, 4, 5],
    2: [1, 2, 3],
    3: [2, 3, 5, 6],
    4: [1, 4, 7],
    5: [2, 4, 5, 6, 8],
    6: [3, 6, 9],
    7: [4, 5, 7, 8],
    8: [7, 8, 9],
    9: [5, 6, 8, 9]
}

// define solution
let solution = "****~****"

// modify string at given index
function setCharAt(str,index,chr) {
    if(index > str.length-1) return str;
    return str.substring(0,index) + chr + str.substring(index+1);
}

// get inputs
function input() {
    var matrix = (readline()+readline()+readline()).replace(/ /g, '');;
    const buttons = readline();
    return [matrix, buttons];
}

// reverse a position
function reverse(square, position) {
    const newSymbol = square.charAt(position - 1) == '*' ? '~' : '*';
    return setCharAt(square, (position-1), newSymbol);
}

// press button
function transform(square, button) {
    for (const b of switches[button]) {
        square = reverse(square, position=b);
    }
    return square;
}

// get solving button
function resolve(square) {
    for (i = 1; i <= 9; i++) {
        if (transform(square, button=i).localeCompare(solution) == 0) {
            console.error("pressing button",i,"solves the square !")
            return i
        }
    }
}

// main sequence
function main() {
    var [square, buttons] = input();
    console.error("input square is:", square);
    console.error("pressed buttons are:", buttons);
    for (const b of buttons) {
        console.error("pressing:",b);
        square = transform(square, button=parseInt(b));
        console.error("got:",square);
    }
    console.log(resolve(square));
}

// run solution
main()
