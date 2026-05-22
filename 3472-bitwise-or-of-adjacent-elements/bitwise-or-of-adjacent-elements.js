/**
 * @param {number[]} nums
 * @return {number[]}
 */
var orArray = function(nums) {
    let ans = []
    for(let i = 0; i < nums.length - 1; i++){
        ans.push(nums[i] | nums[i+1]);
    }
    return ans;
};