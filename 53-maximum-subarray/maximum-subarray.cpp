class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        vector<int>pre=nums;

        for(int i=1;i<nums.size();i++){
            pre[i]+=max(0,pre[i-1]);
        }

        return *max_element(begin(pre),end(pre));
    }
};