//https://www.codingame.com/ide/puzzle/tictactoe
const grille = new Array(3)
for (let i = 0; i < 3; i++) {
    grille[i] = Array.from(readline())
}
console.table(grille)

var win = -1
for (let i = 0; i<3 && win == -1; i++) {
    var count = 0 
    for (let j = 0; i<3 && count < 2; j++) 
        if (grille[i][j] == 'O') count++
    if (count==2) 
        win = i
} 

if (win != -1) 
    for (let i = 0; i<3; i++) grille[win][i] = 'O'

else 
    for (let i = 0; i<3 && win == -1; i++) {
        var count = 0 
        for (let j = 0; i<3 && count < 2; j++) 
            if (grille[j][i] == 'O') 
                count++
        if (count==2) 
            win = i
} 

if (win != -1) 
    for (let i = 0; i<3; i++) 
        grille[i][win] = 'O'

else 
    for (let i = 0; i<3 && win == -1; i++) {
        var count = 0
        if (grille[i][i] == 'O') 
            count++
        if (count==2) 
            win = 0
    } 
    
if (win != -1) 
    for (let i = 0; i<3; i++) 
        grille[i][i] = 'O'
else 
    for (let i = 0; i<3 && win == -1; i++) {
        var count = 0
        if (grille[i][3-i-1] == 'O') 
            count++
        if (count==2) 
            win = 0
} 

if (win != -1) 
    for (let i = 0; i<3; i++) 
        grille[i][3-i-1] = 'O'

string = ''
if (win == -1) 
    console.log('false')
else 
    for (let i = 0; i<3; i++) {
        for (let j = 0; i<3; j++) string += grille[i][j]
        string += '\n'
    }
     
console.log(string);
