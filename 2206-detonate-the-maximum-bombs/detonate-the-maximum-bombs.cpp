class Solution {
public:

    void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node){
        vis[node]=true;


        for(auto neighbour: adj[node]){
            if(!vis[neighbour]){
                dfs(adj,vis,neighbour);
            }
        }
    }
   bool liesInside(int x, int y, int r, int px, int py) {
    long long dx = px - x;
    long long dy = py - y;
    long long distSquared = dx * dx + dy * dy;
    long long radiusSquared = 1LL * r * r;

    return distSquared <= radiusSquared;
}

    int maximumDetonation(vector<vector<int>>& bombs) {
       // find max nodes in a single component 

       // lets represent each circle with a node 0 through n-1
       int n = bombs.size();

       // create adjaceny list
        unordered_map<int,vector<int>>adj(n);
    
       for(int i=0;i<n;i++){
        vector<int>center = bombs[i];
        for(int j=0;j<bombs.size();j++){
            if(i!=j){
                if(liesInside(center[0],center[1],center[2],bombs[j][0],bombs[j][1])){
                    adj[i].push_back(j);
                }

            }
        }
       }

       // now do dfs to find max components traversed
       int maxCount = 0;

       for(int i=0;i<n;i++){
        vector<bool>vis(n,false);
        int count = 0;
        dfs(adj,vis,i);
        for(int i=0;i<vis.size();i++){
            if(vis[i])count++;
        }


        maxCount = max(maxCount,count);
       }

      return maxCount;


    }
};