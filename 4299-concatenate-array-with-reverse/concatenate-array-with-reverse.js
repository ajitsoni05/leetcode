/**
 * @param {number[]} nums
 * @return {number[]}
 */
var concatWithReverse = function(nums) {

    let ans = Array.from(nums);
    ans = ans.concat(nums.reverse());
    return ans;
};