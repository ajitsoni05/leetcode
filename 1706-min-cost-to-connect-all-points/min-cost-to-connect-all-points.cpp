class Solution {
public:
    int dist(vector<int>p1,vector<int>p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // lets do using prim's


        // visited set
        set<int>vis;



        // min heap
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        int n = points.size();
        
        // edges
        vector<vector<pair<int,int>>>adj(n);



        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int node1 = i;
                int node2 = j;

                int wt = dist(points[i],points[j]);
                // push the node
                adj[i].push_back({wt,j});
                adj[j].push_back({wt,i});

            }
        }



        // start with source
        pq.push({0,0});
        
        int cost = 0;


        while(!pq.empty()){

            vector<int> v = pq.top();
            int wt = v[0];
            int node = v[1];
            pq.pop();



            if(vis.count(node))continue;

            vis.insert(node);

            cost += wt;

            for(auto nb:adj[node]){
                if(!vis.count(nb.second)){
                    pq.push({nb.first,nb.second});
                }
            }
        }


        return cost;

    }
};