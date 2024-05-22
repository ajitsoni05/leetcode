class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        long cursum=0;
        int maxfreq=0;

        for(int l=0,r=0;r<nums.size();r++){
            cursum+=nums[r];
            while((long)cursum+k<(long)((long)nums[r]*(r-l+1))){
                cursum-=nums[l];
                l++;
            }
            maxfreq=max(maxfreq,(r-l+1));
        }
        return maxfreq;
    }
};