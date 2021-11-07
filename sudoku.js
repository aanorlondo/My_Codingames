function hasDuplicates(array) {
    return (new Set(array)).size !== array.length;
}

function getColumn(array, col) {
    return array.map(function(row) {
        return row[col];
    });
}

function getSubMatrix(matrix, row, col, len) {
    return matrix.slice(row, row + len).map(row => row.slice(col, col + len));
}

function flatten(matrix) {
  return matrix.reduce(function (flat, toFlatten) {
    return flat.concat(Array.isArray(toFlatten) ? flatten(toFlatten) : toFlatten);
  }, []);
}

var  grille = new Array(9);
for (let i = 0; i < 9; i++) {
    var inputs = readline().split(' ');
    grille[i] = new Array(9);
    for (let j = 0; j < 9; j++) {
        grille[i][j] = parseInt(inputs[j]);
    }
}

//console.table(grille);

var next = true;
for (let i = 0; i < 9 ; i++) {
    if (hasDuplicates(grille[i])) {
        next = false; break; //rows
    }
    if (hasDuplicates(getColumn(grille,i))) {
        next = false; break; //columns
    }
}
for (let i = 0; i < 9; i+=3) {
    for (let j = 0; j < 9; j += 3) {
        if (hasDuplicates(flatten(getSubMatrix(grille,i,j,3))))
        {
            next = false; break; //columns
        }
    }
}
console.log(next);
