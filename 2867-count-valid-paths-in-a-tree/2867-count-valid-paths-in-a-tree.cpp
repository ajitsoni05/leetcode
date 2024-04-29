class DisjointSet{
public:
  vector<int>size,parent;
    
    DisjointSet(int n){
        size.resize(n+1,1);
        size[0]=0;
        parent.resize(n+1,0);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findUParent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findUParent(parent[u]);
    }
   void Union(int u, int v) {
    int up_u = findUParent(u);
    int up_v = findUParent(v);
    if (up_u == up_v) return;
    if (size[up_u] > size[up_v]) {
        parent[up_v] = up_u;
        size[up_u] += size[up_v];
    } else {
        parent[up_u] = up_v;
        size[up_v] += size[up_u]; // Corrected
    }
}

};
class Solution {
public:
    bool isPrime(int n){
        if(n<=1)return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        // Declare a disjoint set
        DisjointSet d(n);
        
        
        // Make a graph
        
        unordered_map<int,vector<int>>g;
        
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            g[x].push_back(y);
            g[y].push_back(x);
            
            if(!isPrime(x)&&!isPrime(y))
            d.Union(x,y);
        }
        
        long long result=0;
        
        for(int i=1;i<=n;i++){
            if(!isPrime(i))continue;
            vector<int>nodes;
            int sum=0;
            
            for(auto nb:g[i]){
                if(isPrime(nb))continue;
                sum+=d.size[d.findUParent(nb)];
                nodes.push_back(d.size[d.findUParent(nb)]);
            }
            result+=sum;
            for(auto j:nodes){
                sum-=j;
                result+=j*sum;
            }
            
            
        }
        return result;
    }
};