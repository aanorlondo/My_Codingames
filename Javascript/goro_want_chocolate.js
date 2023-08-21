// Inputs
var inputs = readline().split(' ');
var h = parseInt(inputs[0]);
var w = parseInt(inputs[1]);

// Resolution
const area = h * w;
var covered_area = 0;
var eaten = 0;

while (covered_area < area) {
    console.error(`--chocolate: ${h} x ${w}`);
    var old_h = h;
    var old_w = w;
    w = Math.round(w / 2);
    h = h - w;
    covered_area += w * h;
    console.error(`eaten: ${h} x ${w} = ${covered_area}`);
    w = old_w - w;
    h = old_h - h;
    eaten += 1;
}

console.log(eaten);
