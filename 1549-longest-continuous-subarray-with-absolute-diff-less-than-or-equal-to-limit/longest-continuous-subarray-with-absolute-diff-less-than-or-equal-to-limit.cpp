class Solution {
public:
    pair<int,int> getMaxMin(map<int,int>&mp){
        return {mp.rbegin()->first,mp.begin()->first};
    }
    int longestSubarray(vector<int>& nums, int limit) {
        // sliding window approach
        
        int l = 0, r = 0;

        map<int,int>mp;
        int maxLen = 0;
        int n = nums.size();

        while(r < n) {
        
            int ele = nums[r];
            mp[ele]++;
            auto [maxm,minm] = getMaxMin(mp);
            int maxDiff = maxm - minm;
            if(maxDiff <= limit){
                maxLen = max(maxLen, (r - l + 1));
            }else{

                while(l <= r and maxDiff > limit) {
                    int ele = nums[l++];
                    if(--mp[ele] == 0)mp.erase(ele);
                    auto [maxm,minm] = getMaxMin(mp);
                    maxDiff = maxm - minm;

                }
                maxLen = max(maxLen,(r-l+1));
            }
            r++;


        }
        return maxLen;

    }
};