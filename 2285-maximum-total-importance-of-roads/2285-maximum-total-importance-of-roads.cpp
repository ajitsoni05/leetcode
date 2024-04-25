class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        // create graph using adjacency list
        // get the graph with most nodes , assign the largest val similarly do the same for others
        // calculate the total value

        unordered_map<int,int>edges;
        unordered_map<int,vector<int>>graph;

        for(int i=0;i<roads.size();i++){

            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
            edges[roads[i][0]]++;
            edges[roads[i][1]]++;
        }
        priority_queue<pair<long,long>>pq;
        for(auto it:edges){
            pq.push({it.second,it.first});
        }
        long long importance=0;
        while(!pq.empty()){
            importance+=pq.top().first*n--;
            pq.pop();
        }
        return importance;
    }
};