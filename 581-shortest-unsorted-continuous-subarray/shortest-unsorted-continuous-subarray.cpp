class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        vector<int>sorted = nums;
        sort(sorted.begin(),sorted.end());

        int n = nums.size();

        int lowestIdx = n+1;
        int highestIdx = 0;

        for(int i = 0; i < n;i++){
            if(sorted[i]!= nums[i]){
                if(lowestIdx == n+1)lowestIdx = i;

                highestIdx = max(highestIdx, i);
            }
        }

        if(lowestIdx == n+1)return 0;
        return highestIdx - lowestIdx +1;
    }
};