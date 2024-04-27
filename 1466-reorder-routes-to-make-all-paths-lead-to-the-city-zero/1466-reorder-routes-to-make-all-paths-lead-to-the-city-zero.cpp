class Solution {
public:
    void dfs(unordered_map<int,vector<pair<int,int>>>&g,int s,vector<bool>&vis,int &ans){

        vis[s]=true;

        for(auto nb:g[s]){
            if(!vis[nb.first]){
                if(nb.second==1)ans++;
                dfs(g,nb.first,vis,ans);
            }
        }
    }   
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>g;
        for(int i=0;i<connections.size();i++){
            g[connections[i][0]].push_back({connections[i][1],1});
            g[connections[i][1]].push_back({connections[i][0],-1});
        }

        vector<bool>vis(n,false);

        int ans=0;

        dfs(g,0,vis,ans);
        return ans;


    }
};