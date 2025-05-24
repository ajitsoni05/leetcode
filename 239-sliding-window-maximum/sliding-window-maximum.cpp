class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>mst;

        for(int i = 0; i < k; i++){
            mst.insert(nums[i]);
        }

        vector<int>ans;

        ans.push_back(*(mst.rbegin()));
        
        for(int i = k;i<nums.size();i++){

            auto it = mst.find(nums[i-k]);

            mst.erase(it);

            mst.insert(nums[i]);

            ans.push_back(*(mst.rbegin()));
        }

        return ans;
    }
};