class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // sliding window problem


        int n = nums.size();
        int maxm = 1;
        for(int i=0;i<n;i++)maxm=max(maxm,nums[i]);
        int left = 0;
        int right = 0;
        int count = 0;
        long long ans = 0;
        while(right<n){
            if(nums[right]==maxm)count++;
            while(count==k){
                count -= nums[left]==maxm ? 1:0;
                left++;
            }
            ans+=left;
            right++;
        }
        return ans;
    }
};