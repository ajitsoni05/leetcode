class Solution {
public:
    void dfs(unordered_map<int,vector<pair<int,int>>>&g,int src,int dest,vector<bool>&v){
        v[src]=true;

        for(auto nb:g[src]){
            if(!v[nb.first]){
                dfs(g,nb.first,dest,v);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        // Make a graph
        unordered_map<int,vector<pair<int,int>>>g;
        
        for(int i=0; i<roads.size(); i++){
            g[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            g[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        // make a visited array
        vector<bool>visited(n+1,false);

        dfs(g,1,n,visited);
        
        int ans=INT_MAX;
      for (int i = 1; i <= n; ++i) {
    if (visited[i]) {
        for (auto& ele : g[i]) {
            ans = min(ans, ele.second);
        }
    }
}

        return ans;
    }
};