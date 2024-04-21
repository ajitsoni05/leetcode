class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // maximal network rank will be  max of sum of number of roads from any pair of     cities and subtracting one if city are interconnected
        //
        //declare a graph
        vector<vector<int>>graph(n,vector<int>(n,0));
        vector<int>road(n,0);
        for(int i=0;i<roads.size();i++){
            road[roads[i][0]]++;
            road[roads[i][1]]++;
            graph[roads[i][0]][roads[i][1]]++;
            graph[roads[i][1]][roads[i][0]]++;

        }
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,(road[i]+road[j]-graph[i][j]));
            }
        }
        return ans;
    }
};