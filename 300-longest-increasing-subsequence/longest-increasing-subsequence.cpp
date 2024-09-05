class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[i],lis[j]+1);
                    ans=max(ans,lis[i]);
                }
            }
        }
        return ans;
    }
};