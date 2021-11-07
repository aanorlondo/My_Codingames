function hasDuplicates(array) {
    return (new Set(array)).size !== array.length;
}

function getColumn(anArray, columnNumber) {
    return anArray.map(function(row) {
        return row[columnNumber];
    });
}

var  grille = new Array(9);
for (let i = 0; i < 9; i++) {
    var inputs = readline().split(' ');
    grille[i] = new Array(9);
    for (let j = 0; j < 9; j++) {
        const n = parseInt(inputs[j]);
        grille[i][j] = n;
    }
}
//console.error('SUDOKO VALIDATOR');
//console.table(grille);

for (let i = 0; i < 9 ; i++) {
    if (hasDuplicates(grille[i])) {
        console.log('false'); break;
    }
    if (hasDuplicates(getColumn(grille,i))) {
        console.log('false'); break;
    }
}
console.log('true');
