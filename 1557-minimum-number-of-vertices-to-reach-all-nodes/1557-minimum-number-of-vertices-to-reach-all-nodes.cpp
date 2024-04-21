class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // Find those nodes in which the incoming edges is not present 
        // the number of such nodes would be the solution 
        // Make a graph of adjaceny list and a visited array
        unordered_map<int,vector<int>>graph;
        vector<bool>visited(n,false);
        
        //Make a graph by traversing the edges
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            visited[edges[i][1]]=true;
        }
        vector<int>nodes;
        for(int i=0;i<n;i++){
            if(!visited[i])nodes.push_back(i);
        }
        return nodes;
    }
};