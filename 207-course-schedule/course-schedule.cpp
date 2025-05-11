class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     /*

        0 to numCourses - 1

        prerequisites [ai, bi]
     
     
     */   


    // order
    vector<int>order;
     // indegree
    vector<int>indegree(numCourses,0);


    // make an adjaceny list first
    unordered_map<int,vector<int>>adj;

     for(int i=0;i<prerequisites.size();i++){
        int from =prerequisites[i][0];
        int to = prerequisites[i][1];

        
        indegree[to]++;


        adj[from].push_back(to);

     }

    // put courses with indegree 0 into queue
    queue<int>nodes;


    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            nodes.push(i);
        }
    }



    while(!nodes.empty()){
        // take out the node

        int node = nodes.front();
        nodes.pop();

        for(auto nb: adj[node]){
            indegree[nb]--;
            if(!indegree[nb]){
                nodes.push(nb);
            }
        }
        order.push_back(node);
       
    }

    if(order.size()==numCourses)return true;
    else return false;

    }
};