class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // make a trust graph
        // see if both the conditions are satisfied
        // Handle corner case
        if(trust.size()==0&&n==1)return 1;
        unordered_map<int,vector<int>>g1;
        unordered_map<int,vector<int>>g2;
        for (int i=0;i<trust.size();i++){
            g1[trust[i][1]].push_back(trust[i][0]);
            g2[trust[i][0]].push_back(trust[i][1]);
        }
        for(auto itr:g1){
            if(itr.second.size()==n-1&&g2[itr.first].size()==0)return itr.first;
        }
        return -1;
    }
};