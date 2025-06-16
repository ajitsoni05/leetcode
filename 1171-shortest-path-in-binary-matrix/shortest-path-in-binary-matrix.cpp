class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        // apply dijkstra's algo and find the ans

        // 01011
        // 11011
        // 11101
        // 10110
        // 11111

        // Get row and column size of the grid
        int n=grid.size();
        

        // we have to initialize a dist, queue and push source into queue

        int sr=0,sc=0;
        if(n==1&&grid[0][0]==0)return 1;
        if(grid[sr][sc]==1)return -1;
        queue<pair<int,pair<int,int>>>q;

        vector<vector<int>>dist(n+1,vector<int>(n+1,1e9));
        
        dist[sr][sc]=1;

        q.push({0,{sr,sc}});

        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int dis=it.first;

            int r=it.second.first;
            int c=it.second.second;

            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==0&&(1+dist[r][c]<dist[nr][nc])){
                    dist[nr][nc]=1+dist[r][c];

                    if(nr==n-1&&nc==n-1){
                        return dist[nr][nc];
                    }
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return -1;
    }
};