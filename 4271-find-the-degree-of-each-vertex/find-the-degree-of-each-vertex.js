/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var findDegrees = function(matrix) {

    let degrees = new Array(matrix.length).fill(0);


    // consider elements on upper diagnoal 

    // forEach has function call over head , 
    
    // matrix.forEach((row, rowIdx) => {
    //     row.forEach((val, colIdx)=>{
    //         if(rowIdx > colIdx) {

    //             if(val) {
    //                 degrees[rowIdx]++;
    //                 degrees[colIdx]++;
    //             }
    //         }
    //     })
    // })
    

    // if we only see upper triangle (colIdx > rowIdx) or lower triangle (rowIdx > colIdx) then we don't need to halve each value like below
    // for(let i = 0; i < degrees.length; i++) degrees[i] = degrees[i] / 2;


    // using for loop is more fast in JS
    for(let r = 0; r < matrix.length; r++){
        for(let c = 0; c < matrix[r].length; c++){
            if (r > c || !matrix[r][c]) continue;

            degrees[r]++;
            degrees[c]++;
            
        }
    }

    return degrees;
};