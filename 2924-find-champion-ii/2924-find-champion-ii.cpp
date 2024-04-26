class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // find edges with zero indegree , if size >0 return -1 else return arr[0]
        vector<int>indegree(n,0);
        
        //candidates
        vector<int>candidates;
        
        //traverse edges to compute indegree
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)candidates.push_back(i);
        }
        
        return candidates.size()==1?candidates[0]:-1;
    }
};