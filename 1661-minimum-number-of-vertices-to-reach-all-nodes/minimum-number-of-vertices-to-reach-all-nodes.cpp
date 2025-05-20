class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int>indegree(n,0);
        vector<int>ans;
        
        int count = 0;

        for(int i = 0; i < edges.size();i++){

            int from = edges[i][0];
            int to = edges[i][1];

            indegree[to]++;

        }

        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};