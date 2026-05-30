/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var countPairs = function(nums, target) {
    nums.sort((a, b) => b - a);

    let countPairs = 0;

    nums.forEach((ele, index) => {
        let upperBoundTarget = target - ele;

        let l = index + 1;
        let r = nums.length - 1;

        while (l <= r) {
            let mid = Math.floor((l + r) / 2);

            if (nums[mid] < upperBoundTarget) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // l is the first index where nums[l] < upperBoundTarget
        countPairs += nums.length - l;
    });

    return countPairs;
};