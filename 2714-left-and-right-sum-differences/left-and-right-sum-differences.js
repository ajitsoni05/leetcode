/**
 * @param {number[]} nums
 * @return {number[]}
 */
var leftRightDifference = function(nums) {
    let len = nums.length;
    let leftSum = [];
    let rightSum = [];
    let lt = 0;
    let rt = 0;
    
    for(let i = 0; i < len; i++){
        leftSum.push(lt);  
        rightSum.unshift(rt); 
        lt += nums[i];
        rt += nums[len - 1 - i];  
    }
    
    let ans = [];
    for(let i = 0; i < len; i++){
        ans.push(Math.abs(leftSum[i] - rightSum[i]))
    }
    return ans;
};