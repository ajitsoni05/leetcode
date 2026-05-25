/**
 * @param {number[]} nums
 * @return {number[]}
 */
var buildArray = function(nums) {
    let ans = [];

    for(let i = 0; i < nums.length; i++){
        let val = nums[nums[i]];
        ans.push(val);
        
    }
    return ans;
};