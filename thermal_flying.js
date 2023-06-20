// paraglider object definition
class Paraglider {
    constructor(grid, width, height) { // get initial position
        const [x,y] = get_position(grid, width, height);
        this.x = x;
        this.y = y;
    }
    set_position(x,y) { // set new position
        this.x = x;
        this.y = y;
    }
    get_position() { // get current position
        return [this.x, this.y];
    }
}

// get initial position
function get_position(grid, width, height) {
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            if (grid[i][j].localeCompare('V') == 0) {
                return [i, j];
            }
        }
    }
}

// run one simulation step
function next_state(paraglider, grid, width, height) {
    var [i, j] = paraglider.get_position();
    new_i = i+1; 
    new_j = j+1;
    if (new_i>=height-1) { // touch the floor
        console.error("paraglider touched the floor ! stopping simulation.");
        return false;
    }
    if (new_j>=width-1) { // out of frame (horizontally)
        console.error("paraglider went of the frame ! stopping simulation.");
        return false;
    }
    while (is_thermal(grid[new_i][new_j])) {
        thermal = thermal_value(grid[new_i][new_j]);
        new_i = Math.min( Math.max(new_i-thermal, height-1), 0);
    }
    paraglider.set_position(new_i, new_j);
    return true;
}

// thermal detect
function is_thermal(position) {
    if (position.localeCompare('.')) {
        return true;
    }
    return false;
}

// thermal value
function thermal_value(thermal) {
    return parseInt(thermal);
}

// display altitude from y
function get_altitude(y,height) {
    return height-y-1;
}

// get inputs
function input() {
    const width = parseInt(readline());
    const height = parseInt(readline());
    const t = parseInt(readline());
    var grid = [];
    for (let i = 0; i < height; i++) {
        const line = readline();
        grid.push(line);
    }
    return [width, height, t, grid];
}

// main
function main() {
    var [width, height, t, grid] = input();
    
    console.error("start simulation");
    console.error(grid);
    var continue_simulation = true;
    const paraglider = new Paraglider(grid, width, height);
    console.error("initial position is:", paraglider.get_position());
    for (tick=1; (tick<=t && continue_simulation); tick++) {
        continue_simulation = next_state(paraglider, grid, height, width);
        console.error(`at t=${tick}, new position is:`, paraglider.get_position());
    }
    const [x, y] = paraglider.get_position();
    console.log(y, get_altitude(x, height));
}

// run
main();
