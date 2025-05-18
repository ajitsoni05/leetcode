class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        // prob array

        // visited array

        // bfs traversal so adj list

        // adj list
        vector<vector<int>>adj(n);

        // fill the adj
        for(int i = 0; i < edges.size(); i++){
            // node 1
            int node1 = edges[i][0]-1;

            int node2 = edges[i][1]-1;

            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        // visitedSet
        unordered_set<int>visitedSet;

        // queue for bfs level order
        queue<int>q;

        // source node
        int source = 0;

        // prob array
        vector<double>prob(n,0);

        prob[source] = 1.0;

        // push node into q
        q.push(source);

        int level = 0;

        while(!q.empty() and level < t){
            int q_size = q.size();
            for(int i = 0;i<q_size;i++){
            // get the node
            int node = q.front();
            
            //pop
            q.pop();

            visitedSet.insert(node);

            // set the prob of unvisited nodes 

            // get the count

            int node_count = 0;

            for(auto neigh:adj[node]){
                if(!visitedSet.count(neigh))node_count++;
            }
            
            // set prob of each unvis node
             for(auto neigh:adj[node]){
                if(!visitedSet.count(neigh)){
                    prob[neigh] = prob[node]/node_count;
                    q.push(neigh);
                }
            }

            if(node_count > 0 ){
                prob[node] = 0;
            }

            }
            level++;

            // set the prob of node to zero
        
        }

        return prob[target-1];
    }
};