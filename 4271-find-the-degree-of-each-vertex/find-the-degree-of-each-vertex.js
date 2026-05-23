/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var findDegrees = function(matrix) {

    let degrees = new Array(matrix.length).fill(0);

    
    matrix.forEach((row, rowIdx) => {
        row.forEach((val, colIdx)=>{
            let isConnected = val;
            

            if(val) {
                degrees[rowIdx]++;
                degrees[colIdx]++;
            }
            
        })
    })

    for(let i = 0; i < degrees.length; i++) degrees[i] = degrees[i] / 2;

    return degrees;
};