/**
 * @param {number[]} nums
 * @return {number}
 */
function getSum(num) {
    let total = 0;
    while(num){
        total += num%10;
        num = Math.trunc(num/10);

    }
    return total
}
var minElement = function(nums) {
    let min = 10001
    nums.forEach((ele) => {
        min = Math.min(min,getSum(ele))
    })
    return min
};