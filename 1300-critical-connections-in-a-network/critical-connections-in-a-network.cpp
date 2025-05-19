class Solution {
private:
int timer = 0;
public:

    vector<vector<int>>bridges;
    void dfs(vector<vector<int>>&adj,unordered_set<int>&visitedSet,int curr,int par,vector<int>&intime,vector<int>&lowestTime){
        visitedSet.insert(curr);

        // mark low and in
        intime[curr] = lowestTime[curr] = timer;

        // increase the timer
        timer++;

        // check for the neighbours

        for(auto neighbour:adj[curr]){

            // if neighbour is parent, continue
            if(neighbour == par) continue;

            // neigh is vis
            if(visitedSet.count(neighbour)){
                // take the low
                lowestTime[curr] = min(lowestTime[curr],lowestTime[neighbour]);

            }else{
                // neigh is not vis

                // call dfs for neigh and then check
                dfs(adj,visitedSet,neighbour,curr,intime,lowestTime);
                // take lowestTime
                lowestTime[curr] = min(lowestTime[curr] ,lowestTime[neighbour]);
                if(lowestTime[neighbour] > intime[curr]){

                    // push into bridges
                    bridges.push_back({neighbour,curr});
                }

            }

        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // tarjan's algo

        // lowest time

        // in time

        // dfs call

        // first adj list
        vector<vector<int>>adj(n);

        // put the connections into adj list

        for(int i = 0; i < connections.size(); i++){

            // both ways
            int node1 = connections[i][0];

            int node2 = connections[i][1];

            adj[node1].push_back(node2);
            adj[node2].push_back(node1); 
        }

        // visited array / set
        unordered_set<int>visitedSet;

        // intime array
        vector<int>intime(n,0);

        // lowest time
        vector<int>lowestTime(n,0);

        // call for dfs
        dfs(adj,visitedSet,0,-1,intime,lowestTime);

        return bridges;


    }
};