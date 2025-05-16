class Solution {
public:

    // DFS
    void dfs(vector<vector<int>>& isConnected, unordered_set<int>&visitedSet ,int source ){
        
        int numNodes = isConnected.size();
        visitedSet.insert(source);


        for(int neighbour = 0; neighbour<numNodes;neighbour++){
            
            if(isConnected[source][neighbour] and !visitedSet.count(neighbour)){
                
                dfs(isConnected, visitedSet, neighbour);
            
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {


        //
        /*
        
                 1   2   3

            1    1   1   0

            2    1   1   0
            
            3    0   0   1

        */

        // visited array | if the nodes have been visited 

        int numNodes = isConnected.size();

        // check null
        if(numNodes == 1 || numNodes == 0) return numNodes;

        // visited Map
        unordered_set<int>visitedSet;

        // Depth First Search Call 

        int start = 0;
        int end = numNodes;

        int numProvinces = 0;

        for(int i = start; i < end; i++){

            if(!visitedSet.count(i)){

                int source = i;
                // call DFS
                dfs(isConnected,visitedSet, source);
                numProvinces++;
                
                

            }

        }

        return numProvinces;








    }
};