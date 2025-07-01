class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        set<pair<int,int>>vis;

        queue<pair<int,int>>q;

        q.push({entrance[0],entrance[1]});
        vis.insert({entrance[0],entrance[1]});

        int dist = 0;

        int m = maze.size();
        int n = maze[0].size();

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                pair<int,int>node = q.front();
                q.pop();

                int x = node.first, y = node.second;

                if(x == 0 || x == m-1 || y == 0 || y == n-1){
                    if(x == entrance[0] and y == entrance[1]){
                        // do nothing
                    }
                    else return dist;
                }

                for(int l = 0; l < dir.size(); l++){
                    int h = x + dir[l].first;
                    int k = y + dir[l].second;

                    if(h < 0 || h >= m || k < 0 || k >= n )continue;

                    if(maze[h][k] == '.' and !vis.count({h,k})){
                        vis.insert({h,k});
                        q.push({h,k});
                    }
                }
            }
            dist++;

        }
        return -1;

    }
};