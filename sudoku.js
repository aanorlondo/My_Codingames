/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

var  grille = new Array(9);
for (let i = 0; i < 9; i++) {
    var inputs = readline().split(' ');
    for (let j = 0; j < 9; j++) {
        grille[j] = new Array(9);
        const n = parseInt(inputs[j]);
        grille[i][j] = n;
    }
}

for (let i = 0; i < 9 ; i++) {
    for (let j = 0 ; j < 9 ; j++) {
        console.error(grille[i][j]);
        for (let v = 0 ; v < 9 ; j++) { //check vertically
            if (grille[i][j] == grille[v][j] && (i != v) ) {
                console.log('false');
                exit(-1);
            }
        }
        for (let h = 0 ; h < 9 ; j++) { //check horizontally
            if (grille[i][j] == grille[i][h] && (j != h) ) {
                console.log('false');
                exit(-1);
            }
        }
        for (v = i - (i % 3) ; i < 8 - i - 3 - (i % 3) ; i++) { //the squares
            for (h = j - (j % 3) ; j < 8 - j - 3 - (j % 3) ; j++) {
                if(grille[i][j] == grille[v][h] && (i != v) && (j != h)) {
                    console.log('false');
                    exit(-1);
                }
            }
        }
    }
}
console.log('true');
