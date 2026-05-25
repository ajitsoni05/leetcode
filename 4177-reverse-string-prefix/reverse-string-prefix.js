/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reversePrefix = function(s, k) {
    let sub = s.substring(k);
    let rev = s.substring(0,k);
    return rev.split('').reverse().join('') + sub;
};