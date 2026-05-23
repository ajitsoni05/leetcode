/**
 * @param {number} n
 * @return {number}
 */
var mirrorDistance = function(n) {
    let num = n.toString().split('').reverse().join('');
    return Math.abs(parseInt(num) - n);
};