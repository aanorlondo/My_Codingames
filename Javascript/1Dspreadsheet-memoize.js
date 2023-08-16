function evaluate(n, memo) {
    memo = memo || {};
        console.error('evaluating line',n);
        if (n in memo) { 
            console.error('line',n,'value already known');
            return memo[n];
        }
        else if (lines[n][0] == 'VALUE') {
            console.error('\treading VALUE');
            memo[n] = (!lines[n][1].includes('$')) ? parseInt(lines[n][1]) : evaluate(parseInt(lines[n][1].substring(1)));
        }
        else if  (lines[n][0] == 'ADD') {
            console.error('\treading ADD');
            memo[n] = (!lines[n][1].includes('$')) ? parseInt(lines[n][1]) : evaluate(parseInt(lines[n][1].substring(1))); 
            memo[n] +=(!lines[n][2].includes('$')) ? parseInt(lines[n][2]) : evaluate(parseInt(lines[n][2].substring(1)));
        }
        else if  (lines[n][0] == 'SUB') {
            console.error('\treading SUB');
            memo[n] = (!lines[n][1].includes('$')) ? parseInt(lines[n][1]) : evaluate(parseInt(lines[n][1].substring(1))); 
            memo[n] -=(!lines[n][2].includes('$')) ? parseInt(lines[n][2]) : evaluate(parseInt(lines[n][2].substring(1)));
        }
        else if  (lines[n][0] == 'MULT') {
            console.error('\treading MULT');
            memo[n] = (!lines[n][1].includes('$')) ? parseInt(lines[n][1]) : evaluate(parseInt(lines[n][1].substring(1))); 
            memo[n] *=(!lines[n][2].includes('$')) ? parseInt(lines[n][2]) : evaluate(parseInt(lines[n][2].substring(1)));
        }
        console.error('\tline',n,'evaluated at',memo[n]);
        if (memo[n] == -0) memo[n] = 0 ;
        return memo[n];
}

const N = parseInt(readline());
let lines = new Array(N);
for (let i = 0; i < N; i++) {
    lines[i] = new Array(3);
    var inputs = readline().split(' ');
    lines[i][0] = inputs[0];
    lines[i][1] = inputs[1];
    lines[i][2] = inputs[2];
}
for (let i = 0; i < N; i++) {
    console.log(evaluate(i));
}
