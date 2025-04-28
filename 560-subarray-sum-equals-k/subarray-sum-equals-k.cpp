class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int presum =0;
        int ans =0;

        for(int i=0;i<nums.size();i++){
            presum+=nums[i];

            if(mp.count(presum-k)){
                ans+=mp[presum-k];
            }
            mp[presum]++;
        }
        return ans;
    }
};