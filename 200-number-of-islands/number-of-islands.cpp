class DST{
    public:
    vector<int>size;
    vector<int>parent;

    DST(int m,int n){
        size.resize(m*n,1);
        parent.resize(m*n);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
    }

   int findUP(int n) {
        if (parent[n] != n) {
            parent[n] = findUP(parent[parent[n]]); // Correct path compression
        }
        return parent[n];
    }
      void Union(int a, int b) {
        int pa = findUP(a);
        int pb = findUP(b);
        if (pa != pb) { // Only unite if they are in different sets
            if (size[pa] > size[pb]) {
                parent[pb] = pa;
                size[pa] += size[pb];
            } else {
                parent[pa] = pb;
                size[pb] += size[pa];
            }
        }
    
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Lets try union find
        int m=grid.size();
        int n=grid[0].size();
        DST ds(m,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i+1<m and j<n and grid[i][j]=='1' and grid[i+1][j]=='1'){
                    ds.Union(i*n+j,(i+1)*n+j);
                }
                if(i<m and j+1<n and grid[i][j]=='1' and grid[i][j+1]=='1'){
                     ds.Union(i*n+j,(i)*n+j+1);
                }
                if(i-1>=0 and grid[i][j]=='1' and grid[i-1][j]=='1'){
                     ds.Union(i*n+j,(i-1)*n+j);
                }
                if(j-1>=0 and grid[i][j]=='1' and grid[i][j-1]=='1'){
                    ds.Union(i*n+j,(i)*n+j-1);
                }
            }
        }
        map<int,int>mp;
        int count=0;
        for(int i=0;i<ds.parent.size();i++){
            int k=i%n;
            int h=i/n;
            if(grid[h][k]=='1'){
                mp[ds.findUP(i)]++;
                cout<<ds.findUP(i)<<endl;
            }

        }
        return mp.size();
    }
    /*
        10111
        10101
        11101
    */
};