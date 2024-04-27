class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& g, int s, vector<bool>& vis, int& cnt_ed, int& cnt_v) {
    vis[s] = true;
    cnt_v += 1;
    for (auto nb : g[s]) {
        cnt_ed += 1;
        if (!vis[nb]) { // Corrected the condition to check vis[nb]
            dfs(g, nb, vis, cnt_ed, cnt_v);
        }
    }
}

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // create an adjacency list, visited
        // do dfs and count the number of nodes and edges 
        // if edges == nodes*(nodes-1)/2 , then its a complete component
        
        unordered_map<int,vector<int>>g;
        
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
            
        }
        int cnt=0;
        
        vector<bool>vis(n,false);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cnt_ed=0;
                int cnt_v=0;
                dfs(g,i,vis,cnt_ed,cnt_v);
                
                if((cnt_v*(cnt_v-1))==cnt_ed)cnt++;
            }
        }
        
        return cnt;
        
    }
};