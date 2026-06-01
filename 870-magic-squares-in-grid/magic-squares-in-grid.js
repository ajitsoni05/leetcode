/**
 * @param {number[][]} grid
 * @return {number}
 */

function isMagicSquare(grid, i, j){
  let sum = -1
  let mp = new Map([[1,0],
  [2,0],
  [3,0],
  [4,0],
  [5,0],
  [6,0],
  [7,0],
  [8,0],
  [9,0]])
  for(let h = i; h < i+3; h++){
    let curSum = 0
     for(let k = j; k < j+3; k++){
        curSum += grid[h][k];
        let val = mp.get(grid[h][k])
        if(val === undefined)return false
        else if(val === 1)return false
        else mp.set(grid[h][k],1)
     }
     if(sum === -1)sum = curSum
     else if(sum !== curSum)return false
  }

   for(let h = j; h < j+3; h++){
    let curSum = 0
     for(let k = i; k < i+3; k++){
        curSum += grid[k][h];
     }
     if(sum !== curSum)return false
  }

  let diag1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]
  let diag2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2]

  return diag1 === diag2
}
var numMagicSquaresInside = function(grid) {
    
    let m = grid.length
    let n = grid[0].length
    let count = 0

    for(let i = 0; i < m - 2; i++) {
        for(let j = 0; j < n - 2; j++) {
            count += isMagicSquare(grid, i, j)
        }
    }
    return count
};