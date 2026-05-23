/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minOperations = function(nums, k) {
    // get total sum and return total_sum % k


    let total = 0;

    // nums.forEach((ele) => {total += ele});

    // let's try to use accumulator which is reduce method in js
    total = nums.reduce((accumulator,currentValue) => accumulator+currentValue);

    return total%k;
};