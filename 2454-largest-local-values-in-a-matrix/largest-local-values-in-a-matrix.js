/**
 * @param {number[][]} grid
 * @return {number[][]}
 */

function getMax(grid, i, j) {

    let maxm = grid[i][j];

    for (let h = -1; h <= 1; h++) {
        for (let k = -1; k <= 1; k++) {
            maxm = Math.max(maxm, grid[i + h][j + k]);
        }
    }
    return maxm;
}
var largestLocal = function (grid) {

    let n = grid.length;
    let result = Array(n - 2).fill().map(() => Array(n - 2).fill(0));

    
    for (let i = 1; i < n - 1; i++) {
        for (let j = 1; j < n - 1; j++) {
            result[i - 1][j - 1] = getMax(grid, i, j);
        }
    }
    return result
    

};