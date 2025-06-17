class dst{
  public:
  vector<int>rank;
  vector<int>parent;
  int n ;
  dst(int numNodes):n(numNodes){
    rank.resize(numNodes,1);
    for(int i = 0; i < numNodes; i++){
        parent.push_back(i);
    }
  } 
 int find(int x){
    if(x == parent[x])return x;
    return parent[x] = find(parent[x]);
 }
 bool un(int x,int y){
    int rx = find(x);
    int ry = find(y);

    if(rx != ry){
        if(rank[rx] > rank[ry]){
            parent[ry] = rx;
        }else if(rank[ry] > rank[rx]){
            parent[rx] = ry;
        }else{
            parent[ry] = rx;
            rank[rx]++;
        }

        return true;
    }
    return false;
 }
};
class Solution {
public:
    int dist(vector<int>p1,vector<int>p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,pair<int,int>>mp;

        int n = points.size();

        vector<vector<int>>edges;

        for(int i =0; i < points.size();i++){
            for(int j = i+1; j <points.size();j++){
                int distance = dist(points[i],points[j]);
                edges.push_back({distance,i,j});
            }
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        for(int i = 0; i < edges.size();i++){
            pq.push(edges[i]);
        }

        int iter = 0;
        dst ds = dst(n);
        int cost = 0;

        while(iter != n - 1){
            vector<int>tp;
            if(!pq.empty()){
                tp = pq.top();
                pq.pop();
            }
            int x = tp[1],y =tp[2];

            if(ds.un(x,y)){
                cost += tp[0];
                iter++;
            }
            
        }
        return cost;
    }
};