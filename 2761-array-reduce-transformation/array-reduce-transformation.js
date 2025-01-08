/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    
    // // imperative way
    // return nums.reduce(fn,init)

    // declarative way


    // for(let i=0;i<nums.length;i++){
    //     init = fn(init,nums[i])
    // }
    // return init

    nums.forEach((n)=>{
        init =fn(init,n)
    })
    return init


};