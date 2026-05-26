/**
 * @param {string} s
 * @return {number}
 */
var reverseDegree = function(s) {
    
    let z = 'z'.charCodeAt(0) + 1;
    let total = 0;
    [...s].forEach((char,index)=>{
        let charCode = char.charCodeAt(0);
        total += ((z-charCode )*(index + 1));
    })
    return total;
};