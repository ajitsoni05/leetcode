class Solution {
public:
    void dfs(  unordered_map<int,vector<int>>&g,int s,int& cnt, vector<bool>&vis, unordered_set<int>& r){
        vis[s]=true;
        cnt++;
        for(auto nb:g[s]){
            if(r.find(nb)==r.end()&&!vis[nb]){
            dfs(g,nb,cnt,vis,r);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // make a graph,vis
        // dfs from src 
        // count num of vis
         unordered_set<int> restrictedSet(restricted.begin(), restricted.end());

        unordered_map<int,vector<int>>g;

        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool>vis(n,false);

        int ans=0;
        dfs(g,0,ans,vis,restrictedSet);

        return ans;

    }
};