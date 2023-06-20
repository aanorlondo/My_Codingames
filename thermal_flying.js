// paraglider object definition
class paraglider {
    constructor(grid, width, height) { // get initial position
        [x,y] = get_position(grid, width, height);
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
    for (i=0; i<width; i++) {
        for (j=0; j<height; j++) {
            if (grid[i][j].localeCompare('V') == 0) {
                return [i, j];
            }
        }
    }
}

// run one simulation step
function next_state(paraglider, grid, height, width, t) {
    var [x, y] = paraglider.get_position();
    new_x = x+1; 
    new_y = y+1;
    if (x>width) { // out of frame (horizontally)
        return [true, x, y]
    }
    if (y>height) { // touch the floor
        return [true, x, y]
    }
    
}

// display position
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
    console.error("initial position is:", get_position(grid,width,height));
    console.log(grid);
}

// run
main();
