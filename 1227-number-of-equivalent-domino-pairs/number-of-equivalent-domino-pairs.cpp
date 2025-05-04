class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string,int>mp;

        for(int i=0;i<dominoes.size();i++){
            int minm = min ( dominoes[i][0],dominoes[i][1]);
            int maxm = max ( dominoes[i][0],dominoes[i][1]);
            string str = to_string(minm) +","+ to_string(maxm);
            mp[str]++;
        }

        int ans =0;


        for(auto it:mp){
            int n = it.second;
            ans += ((n)*(n-1))/2;
        }
        return ans;
    }
};