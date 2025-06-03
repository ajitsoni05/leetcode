class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {
        // find number of components 
        

        // build adj
        vector<vector<int>>adj(n);

        int m = connections.size();
        
        for(int i = 0; i < m;i++) {
            int node1 = connections[i][0];
            int node2 = connections[i][1];

            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        
        vector<bool>vis(n,false);

        int numComp = 0;

        for(int i = 0; i < n;i++){
            if(!vis[i]){
                numComp++;

                int start = i;
                queue<int>q;

                q.push(start);
                vis[start]=true;

                while(!q.empty()){

                    int node = q.front();
                    q.pop();
                    for(auto nb:adj[node]){
                        if(!vis[nb]){
                            vis[nb] = true;
                            q.push(nb);
                        }
                    }
                    
                }
            }
        }

        int numEdges = m;
        int totalCables = m;
        return totalCables + 1 < n ? -1:numComp -1;
    }
};