function hasDuplicates(array) {return (new Set(array)).size !== array.length;}
function getColumn(array, col) { return array.map(function(row) {return row[col];});}
function getSubMatrix(matrix, row, col, len) {return matrix.slice(row, row + len).map(row => row.slice(col, col + len));}
function flatten(matrix) {return matrix.reduce(function (flat, toFlatten) 
    {return flat.concat(Array.isArray(toFlatten) ? flatten(toFlatten) : toFlatten);}, []);}
var  grille = new Array(9); var next = true;
for (let i = 0; i < 9; i++) {
    var inputs = readline().split(' '); grille[i] = new Array(9);
    for (let j = 0; j < 9; j++) { grille[i][j] = parseInt(inputs[j]);}}
for (let i = 0; i < 9 ; i++) {
    if (hasDuplicates(grille[i])) {next = false; break;}
    if (hasDuplicates(getColumn(grille,i))) {next = false; break;}}
for (let i of [0, 3, 6]) {
    for (let j of [0, 3, 6]) {
        if (hasDuplicates(flatten(getSubMatrix(grille,i,j,3)))){next = false; break;}}}
console.log(next);
