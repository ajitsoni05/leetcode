class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&g,int s,int cur, vector<bool>&vis,vector<vector<int>>&ans){
        vis[cur]=true;
        for(auto nb:g[cur]){
            if(!vis[nb]){
                ans[s].push_back(nb);
                dfs(g,s,nb,vis,ans);
            }
        }

       
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>>g;
        for(int i=0;i<edges.size();i++){
            g[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<vector<int>>ans(n);

        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            dfs(g,i,i,vis,ans);
            sort(ans[i].begin(),ans[i].end());
            
        }
        
        return ans;
       

    }
};