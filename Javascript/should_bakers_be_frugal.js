var inputs = readline().split(' ');
var side = parseFloat(inputs[0]);
const diameter = parseFloat(inputs[1]);
const biscuit_area = Math.PI * diameter * 0.5 * diameter * 0.5;
wasteful = Math.floor(side / diameter) * Math.floor(side / diameter);
frugal = Math.floor((side * side - diameter * diameter + biscuit_area) / biscuit_area);
console.log(frugal - wasteful)