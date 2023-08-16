function hasDuplicates(array) {
    return (new Set(array)).size !== array.length;
}

function getColumn(array, col) {
    return array.map(function(row) {
        return row[col];
    });
}

var  grille = new Array(9);
for (let i = 0; i < 9; i++) {
    var inputs = readline().split(' ');
    grille[i] = new Array(9);
    for (let j = 0; j < 9; j++) {
        grille[i][j] = parseInt(inputs[j]);
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
