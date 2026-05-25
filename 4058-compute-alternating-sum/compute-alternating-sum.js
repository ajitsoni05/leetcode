/**
 * @param {number[]} nums
 * @return {number}
 */
var alternatingSum = function(nums) {
    let totalSum = 0;

    for(let i = 0; i < nums.length; i++){
        totalSum += i % 2 ? -nums[i] : nums[i];
    }
    return totalSum;
};