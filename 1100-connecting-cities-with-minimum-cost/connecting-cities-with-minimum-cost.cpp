class DST{
    public:
    vector<int>parent;
    vector<int>rank;

    DST(int n){
        rank.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(x == parent[x])return x;
        // path compression
        return x = find(parent[x]);
    }

    bool Union(int x, int y){
        int rx = find(x);
        int ry = find(y);

        if(rx != ry){
            if(rank[rx] > rank[ry]){
                parent[ry] = rx;
            }else if(rank[ry] > rank[rx]){
                parent[rx] = ry;
            }else{
                parent[ry] = rx;
                rank[rx]+=1;
            }
            return true;
        }
        return false;
    }   

    

};
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // priority_queue that holds pair of wt and connection index;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;


        // also build adj list alongside
        for(int i = 0; i < connections.size(); i++){
            int node1 = connections[i][0];
            int node2 = connections[i][1];
            int wt = connections[i][2];

            pq.push({wt,i});
        }

        // dst

        DST dsu = DST(n);

        int cost = 0;

        while(!pq.empty()) {
            pair<int,int>p = pq.top();
            pq.pop();   

            int wt = p.first;
            int index = p.second;

            // nodes
            int node1 = connections[index][0];
            int node2 = connections[index][1];

            bool gotConnected = dsu.Union(node1,node2);
            
            if(gotConnected){
                cost += wt;
            }


        }

        // check number of unique parents
        bool totallyConnected = true;
        for(int i = 1; i < n; i++){
            if(dsu.find(i-1) != dsu.find(i))totallyConnected = false;
        }
        return totallyConnected?cost:-1;



    }
};