class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // we can use bellman ford algo here
        vector<vector<int>>g(n,vector<int>(n,10001));

        

        for(int i=0;i<edges.size();i++){
           
           int x=edges[i][0];
           int y=edges[i][1];
           int w=edges[i][2];

           g[x][y]=w;
           g[y][x]=w;
            
        }

        for(int k=0;k<n;k++){
            for(int j=0;j<n;j++){
                for(int i=0;i<n;i++){
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++)g[i][i]=0;

        int ans=-1;
        int maxm=10000;
        for(int i=n-1;i>=0;i--){
            int count=0;
            for(int j=0;j<n;j++){
                if(g[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<maxm and count>=1){
                maxm=count;
                ans=i;
            }
        }
        return ans;
    }
};