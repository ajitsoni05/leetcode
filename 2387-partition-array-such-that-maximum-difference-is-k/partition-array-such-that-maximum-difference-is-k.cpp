class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int num = nums[0];
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(abs(nums[i]-num) > k){count++;num = nums[i];}
            else{
                num = min(num,nums[i]);
            }
        }
        return count+1;
    }
};