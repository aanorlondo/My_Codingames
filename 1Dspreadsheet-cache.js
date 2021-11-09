const memeval = n => {
    const cache = []; const evaluate = n => {
        console.error('evaluating line',n);
        if (n in cache) { 
            console.error('line',n,'value already known');
            return cache[n];
        }
        else if (lines[n][0] == 'VALUE') {
            console.error('\treading VALUE');
            cache[n] = (!lines[n][1].includes('$')) ? parseInt(lines[n][1]) : evaluate(parseInt(lines[n][1].substring(1)));
        }
        else if  (lines[n][0] == 'ADD') {
            console.error('\treading ADD');
            cache[n] = (!lines[n][1].includes('$')) ? parseInt(lines[n][1]) : evaluate(parseInt(lines[n][1].substring(1))); 
            cache[n] +=(!lines[n][2].includes('$')) ? parseInt(lines[n][2]) : evaluate(parseInt(lines[n][2].substring(1)));
        }
        else if  (lines[n][0] == 'SUB') {
            console.error('\treading SUB');
            cache[n] = (!lines[n][1].includes('$')) ? parseInt(lines[n][1]) : evaluate(parseInt(lines[n][1].substring(1))); 
            cache[n] -=(!lines[n][2].includes('$')) ? parseInt(lines[n][2]) : evaluate(parseInt(lines[n][2].substring(1)));
        }
        else if  (lines[n][0] == 'MULT') {
            console.error('\treading MULT');
            cache[n] = (!lines[n][1].includes('$')) ? parseInt(lines[n][1]) : evaluate(parseInt(lines[n][1].substring(1))); 
            cache[n] *=(!lines[n][2].includes('$')) ? parseInt(lines[n][2]) : evaluate(parseInt(lines[n][2].substring(1)));
        }
        console.error('\tline',n,'evaluated at',cache[n]);
        if (cache[n] == -0) cache[n] = 0 ;
        return cache[n];
    }; return evaluate(n);
};

const N = parseInt(readline());
let lines = new Array(N);
for (let i = 0; i < N; i++) {
    lines[i] = new Array(3);
    var inputs = readline().split(' ');
    lines[i][0] = inputs[0];
    lines[i][1] = inputs[1];
    lines[i][2] = inputs[2];
}
//console.table(lines);
for (let i = 0; i < N; i++) {
    console.log(memeval(i));
}
