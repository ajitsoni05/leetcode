class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>>numIdxs;


        int n = nums.size();
        int l = 0, r = n - 1;

        for(int i = 0; i < n; i++){
            numIdxs.push_back({nums[i],i});
        }


        sort(numIdxs.begin(),numIdxs.end());



        while(l < r){
            int sum = numIdxs[l].first + numIdxs[r].first;

            if(sum < target){
                l++;
            }else if(sum > target)r--;
            else return {numIdxs[l].second,numIdxs[r].second};
        }

        return {};
    }
};