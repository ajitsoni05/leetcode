class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>numsI;

        for(int i = 0; i < nums.size(); i++) {
            numsI.push_back({nums[i],i});
        }


        sort(numsI.begin(),numsI.end());

        int l = 0, r = nums.size() - 1;
        
        while (l < r) {
            int sum = numsI[l].first + numsI[r].first;

            if(sum < target){
                l++;
            }else if (sum == target){
                return {numsI[l].second,numsI[r].second};
            }else {
                r--;
            }
        }
        return {0,0};
    }
};