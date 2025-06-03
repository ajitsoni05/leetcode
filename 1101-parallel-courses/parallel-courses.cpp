class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        // number of level traversed in the topo sort is min number of sem
        // Kahn's algo        

        // indegree array
        vector<int>indegree(n+1,0);

        // let's create an adjacency list first
        vector<vector<int>>adj(n+1);

        // build adj

        for(int i = 0; i < relations.size(); i++){
            int node1 = relations[i][0];
            int node2 = relations[i][1];

            indegree[node2]++;
            adj[node1].push_back(node2);
        }   


       

        // queue 
        queue<int>q;


        for(int i = 1; i < indegree.size();i++){
            if(indegree[i]==0)q.push(i);
        }
        
        int numSem = 0;
        set<int>visitedSet;

        while(!q.empty()){

            int size = q.size();
            
            for(int i = 0; i < size; i++){

                int node = q.front();
                q.pop();
                visitedSet.insert(node);
                for(auto nb:adj[node]){
                    if(--indegree[nb]==0)q.push(nb);
                    
                }
            }
            numSem++;

        }

        return numSem and visitedSet.size() == n ? numSem : -1;

        
    }
};