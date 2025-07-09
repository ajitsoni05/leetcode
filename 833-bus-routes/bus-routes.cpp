class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>adj;
        if(source == target)return 0;

        for(int route = 0; route < routes.size(); route++){
            for(auto& stop:routes[route]){
                adj[stop].push_back(route);
            }
        }


        // find source stop routes

        queue<int>q;
        set<int>vis;

        for(auto routeIndex:adj[source]){
            q.push(routeIndex);
            vis.insert(routeIndex);
        }

        int busCount = 1;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                int routeIndex = q.front();
                q.pop();

                for(int i = 0; i < routes[routeIndex].size();i++){
                    if(routes[routeIndex][i] == target)return busCount;

                    for(auto route:adj[routes[routeIndex][i]]){
                        if(!vis.count(route)){
                            q.push(route);
                            vis.insert(route);
                        }
                    }
                }
            }
            busCount++;

        }
        return -1;


    }
};