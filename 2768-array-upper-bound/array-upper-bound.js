/** 
 * @param {number} target
 * @return {number}
 */
Array.prototype.upperBound = function(target) {
    let idx =-1;
    let nums = this;
    console.log(nums)
    for(let i=0;i<nums.length;i++){
        if(target==nums[i])idx=i;
    }
    return idx;
};


// [3,4,5].upperBound(5); // 2
// [1,4,5].upperBound(2); // -1
// [3,4,6,6,6,6,7].upperBound(6) // 5