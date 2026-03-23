class Solution {
public:
    vector<int> reverseSubarrays(vector<int>& nums, int k) {
        int len = nums.size()/k;
        for(int i = 0; i <= nums.size() - len; i+=len){
            reverse(nums.begin()+i,nums.begin()+i+len);
        }
        return nums;
    }
};