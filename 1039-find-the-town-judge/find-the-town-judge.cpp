class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // check the indegree and outdegree
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);

        for(int i = 0; i <trust.size();i++){
            int to = trust[i][1];
            int from = trust[i][0];

            indegree[to]++;
            outdegree[from]++;
        }


        for(int i =1; i <=n;i++){
            if(indegree[i]==n-1 and outdegree[i]==0)return i;
        }
        return -1;
    }
};