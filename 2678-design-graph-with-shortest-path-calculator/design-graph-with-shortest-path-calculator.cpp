class Graph {
public:

    // we will use floyd warshall
    vector<vector<int>>graph;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        graph.resize(n,vector<int>(n,100000000));
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            int w=edges[i][2];
            graph[x][y]=w;
        }
        // apply floyd warshall
        for(int i=0;i<n;i++)graph[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
         int x=edge[0];
            int y=edge[1];
            int w=edge[2];
            graph[x][y]=w;
             for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                   graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        if(graph[node1][node2]==100000000)return -1;
        else return graph[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */