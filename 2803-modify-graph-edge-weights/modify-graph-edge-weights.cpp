class Solution {
public:

    long long runDijikstra(int n, vector<vector<int>>& edges, int source, int destination){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        vector<vector<pair<int,int>>>adj(n);

        int edgesCount = edges.size();

        for(int i = 0; i < edgesCount; i++){

            
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            
            int weight = edges[i][2];

            if(weight == -1) weight = 2e9;

            adj[node1].push_back({node2,weight});
            adj[node2].push_back({node1,weight});

        }
        
        vector<long long>distance(n,2e9);

        distance[source] = 0;

        minHeap.push({distance[source],source});

        while(!minHeap.empty()){

            auto ele = minHeap.top();
            minHeap.pop();

            int node = ele.second;
            int weight = ele.first;

            for(auto neighbour:adj[node]){

                int nghNode = neighbour.first;
                long long nghDist = neighbour.second;

                long long curr = weight + nghDist;

                if( curr < distance[nghNode]){

                    distance[nghNode] = curr;
                    
                    minHeap.push({curr,nghNode});
                }
            }
        }

        return distance[destination];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination,int target) {
    
        int currentMinDistance = runDijikstra(n,edges,source,destination);

        bool matchesTarget = currentMinDistance == target;


        // if currentMinDistance is less than target return {{}}

        if(currentMinDistance < target) return {};

        
        // go through the edges

        for(int i = 0; i < edges.size();i++){

            // if edge is positive weight continue;
            int weight = edges[i][2];

            if(weight >= 0)continue;

            // if(weight == -1){
                
            //     // if matchesTarget set currentedge to INF
            //     if(matchesTarget){
            //         edges[i][2] = 2e9;
            //     }else{
            //         edges[i][2] = 1;
            //     }
            // }


            if(matchesTarget){
                if(weight == -1)
                edges[i][2] = 2e9;
            }else{

                edges[i][2] = 1;

                currentMinDistance = runDijikstra(n,edges,source,destination);


                if(currentMinDistance <= target){
                    edges[i][2] += target - currentMinDistance;
                    matchesTarget = true;
                }


            }
            


            // runDijikstra with new edges

            
            

        }
        
        vector<vector<int>>empty(0);
        return matchesTarget == true ? edges : empty;

        

      



    }
};