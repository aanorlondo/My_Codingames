var influences = {}; // {x:Set()}
var depths = {}; // {x:number} 
var max = 0

function get_depth(x) {
    if (x in depths) return depths[x];
    const ys = influences[x];
    var max_y_depth = 0;
    var y_depth = 0;
    for (const y of ys) {
        if (y in depths) y_depth = 1 + depths[y];
        else {
            if (y in influences) y_depth = 1 + get_depth(y);
            else y_depth = 1
        }
        if (y_depth > max_y_depth) max_y_depth = y_depth;
    }
    x_depth = max_y_depth;
    depths[x] = x_depth;
    if (x_depth > max) max = x_depth;
    return x_depth;
}

const n = parseInt(readline());
for (let i = 0; i < n; i++) {
    var inputs = readline().split(' ');
    x = inputs[0];
    y = inputs[1];
    (x in influences) ? influences[x].add(y) : influences[x] = new Set().add(y);
}

for (x in influences) get_depth(x);

console.log(max + 1);