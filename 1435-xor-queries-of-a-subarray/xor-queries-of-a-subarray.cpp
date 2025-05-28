class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // prefix array for xor
        vector<int>pre;

        pre.push_back(arr[0]);

        int n = arr.size();
        int curr = arr[0];

        for(int i = 1; i < n; i++){
            pre.push_back(curr^arr[i]);
            curr = curr^arr[i];
        }

        vector<int>ans;

        for(int i = 0;i <queries.size();i++){
            int idx1 = queries[i][0];
            int idx2 = queries[i][1];
            if(idx1 == idx2) ans.push_back(arr[idx1]);
            else if(idx1 == 0)ans.push_back(pre[idx2]);
            else ans.push_back(pre[idx1-1]^pre[idx2]);
        }
        return ans;
    }
};