//turns an array (1D) to a set to directly see if it had duplicates (a set can't hold duplicates)
function hasDuplicates(array) {
    return (new Set(array)).size !== array.length;
}

//to get any column from a grid
function getColumn(array, col) { //
    return array.map(function(row) {
        return row[col];
    });
}

//get a sub grid from the main grid
function getSubMatrix(matrix, row, col, len) {
    return matrix.slice(row, row + len).map(row => row.slice(col, col + len));
}

//flattens a matrix (or grid) i.e. in 2D into an array of 1D
function flatten(matrix) {
  return matrix.reduce(function (flat, toFlatten) {
    return flat.concat(Array.isArray(toFlatten) ? flatten(toFlatten) : toFlatten);
  }, []);
}

//we first build the game grid (grille) as a 9x9 matrix from the inputs
var  grille = new Array(9);
for (let i = 0; i < 9; i++) {
    var inputs = readline().split(' ');
    grille[i] = new Array(9);
    for (let j = 0; j < 9; j++) {
        grille[i][j] = parseInt(inputs[j]);
    }
}

var next = true;
for (let i = 0; i < 9 ; i++) {
    /*CHECKING THE ROWS*/
    if (hasDuplicates(grille[i])) {
        //grid -> row as array --set--> check duplicates
        next = false; break;
    }
    /*CHECKING THE COLUMNS*/
    if (hasDuplicates(getColumn(grille,i))) {
        //grid -> column as array --set--> check duplicates
        next = false; break;
    }
}
/*CHECKING THE 9 SUB GRIDS*/
for (let i of [0, 3, 6]) {
    for (let j of [0, 3, 6]) {
        //here is a sexy way to do it : game grid -> sub grid --flatten--> array --set--> check duplicates
        if (hasDuplicates(flatten(getSubMatrix(grille,i,j,3))))
        {
            next = false; break;
        }
    }
}
console.log(next);
//UNCOMM ME !!! --> console.table(grille);
