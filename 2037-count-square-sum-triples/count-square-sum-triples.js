/**
 * @param {number} n
 * @return {number}
 */
var countTriples = function (n) {

    let count = 0
    for (let i = 1; i <= n - 2; i++) {
        for (let j = i + 1; j <= n - 1; j++) {
            for (let k = j + 1; k <= n; k++) {
                if(i*i + j*j === k*k)count++;
            }
        }
    }
    return count*2
};