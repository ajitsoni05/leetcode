class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        /*
        
            wells[i-1] ith house 
            
            pipej = h1j,h2j,cj

            0th node (imaginary node)
        
        
        */

        vector<vector<pair<int,int>>>adj(n+1);

        int numPipes = pipes.size();
        

        // connections

        for(int i = 0; i< numPipes; i++){
          
            // connect both ways
            int h1 = pipes[i][0];
            int h2 = pipes[i][1];
            int cost = pipes[i][2];

            adj[h1].push_back({h2,cost});

            adj[h2].push_back({h1,cost});
        }

        // min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        // push the imaginary edges into min heap
        int numWells = wells.size();

        for(int i = 0; i < numWells; i++){
            
            int wellCost = wells[i];
            int node = i+1;
            minHeap.push({wellCost,node});

            // also add to graph
            adj[0].push_back({node,wellCost});
            adj[i+1].push_back({0,wellCost});
        }

        // mstSet
        set<int>mstSet;

        // source visited
        mstSet.insert(0);


        // add to cost
        int totalCost = 0;

        while(minHeap.size() != 0 and mstSet.size() <= n){

            // get the top
            pair<int,int> p = minHeap.top();

            // first is cost 
            int cost = p.first;

            // second is node
            int node = p.second;

            // pop
            minHeap.pop();

            // check if node is there in the set
            if(mstSet.count(node))continue; 

            // add to cost
            totalCost += cost;

            // insert into set
            mstSet.insert(node);

            if(adj[node].size() == 0) continue;
            // check neighbours 
            for(auto neigh:adj[node]){

                int neighNode = neigh.first;
                int neighCost = neigh.second;

                minHeap.push({neighCost,neighNode});
            }

        }

        return totalCost;


    }
};