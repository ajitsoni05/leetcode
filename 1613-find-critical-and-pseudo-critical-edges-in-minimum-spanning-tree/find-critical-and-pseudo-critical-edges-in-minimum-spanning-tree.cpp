class DSU{
    public:
    vector<int>parent;
    vector<int>rank;

    DSU(int n){
        parent.resize(n,0);
        rank.resize(n,1);

        // init parent
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(x == parent[x])return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa != pb){
            if(rank[pa] > rank[pb]){
                parent[pb] = pa;
            }else if(rank[pb] > rank[pa]){
                parent[pa] = pb;
            }else{
                parent[pb] = pa;
                rank[pa]++;
            }
            return true;
        }
        return false;
    }
};
class Solution {
public:
    pair<int,int> getMST(int n,vector<vector<int>>& edges,int forced = -1){

        // adj
        vector<vector<int>>adj(n);

        // create the graph

        // priority queue for edge weights
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;


        
        for(int i = 0; i < edges.size(); i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int wt = edges[i][2];

            adj[node1].push_back(node2);
            adj[node2].push_back(node1);

            pq.push({wt,i});


        }

        // construct 
        DSU dst = DSU(n);

        // priority queue
        int cost = 0;
        

        if(forced != -1){
            vector<int>ed = edges[forced];
            int n1 = ed[0];
            int n2 = ed[1];
            int wt = ed[2];

            dst.Union(n1,n2);
            cost += wt;
            edges[forced][2] = INT_MAX;
        }

        while(!pq.empty()) {

            auto [wt,edgeIndex] = pq.top();
            
            pq.pop();

            if(wt == INT_MAX)continue;

            int node1 = edges[edgeIndex][0];
            int node2 = edges[edgeIndex][1];

            // union 
            bool gotConnected = dst.Union(node1,node2);

            if(gotConnected) cost += wt;

            
        }

        int numComponents = 0;
        unordered_map<int,int>mp;

        for(int i = 0; i < n; i++){
            mp[dst.find(i)]++;
        }

        return {cost,mp.size()};

        
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // critical are the ones which are present in every mst
        // pseudo-critical are the ones which are non critical and are not present in every mst
       
       // find the mst weight??

       auto[initialCost,numComponents] = getMST(n,edges);

       vector<vector<int>>result;

        set<int>crit;

        // Find critical 
        vector<int>critical;
        for(int i = 0; i < edges.size(); i++){
            vector<vector<int>>copiedEdges = edges;

            copiedEdges[i][2] = INT_MAX;

            pair<int,int>res = getMST(n,copiedEdges);

            if(res.first > initialCost || res.second > numComponents){
                critical.push_back(i);   
                crit.insert(i);
            }


        }
        result.push_back(critical);

        // Find pseudocritical
        vector<int>pseudocritical;
        for(int i = 0; i < edges.size(); i++){
            if(crit.count(i))continue;

            vector<vector<int>>copiedEdges = edges;
            // copiedEdges[i][2] = INT_MAX;
            // force the edge
            pair<int,int>res = getMST(n,copiedEdges,i);

            if(res.first == initialCost ){
                pseudocritical.push_back(i);
            }



        }
        result.push_back(pseudocritical);

        return result;
    }
};