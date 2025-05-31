class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>nums;

        for(int i = 0; i < n; i++){
            nums.push_back(to_string(i+1));
        }

        sort(nums.begin(),nums.end());
        

        vector<int>ans(n);

        for(int i = 0; i< n;i++){
            ans[i] = stoi(nums[i]);
        }
        return ans;
    }
};