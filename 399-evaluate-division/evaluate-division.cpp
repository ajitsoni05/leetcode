class Solution {
public:

    void dfs(unordered_map<string,vector<pair<string,double>>>&adj,unordered_map<string,bool>&vis,string src, string dest,double cur,double&value,bool&reached){
        if(vis.count(src))
        vis[src] = true;


        if(src == dest && vis.count(src)){
            value = cur;
            reached = true;
            vis[src] = false;
            return ;
        }

        for(auto it: adj[src]){
            if(!vis[it.first]){
                dfs(adj,vis,it.first,dest,cur*it.second,value,reached);
            }
        }

        if(vis.count(src))
        vis[src] = false;

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        

        // create an unordered_map to symbolize a graph
        // also weight
        unordered_map<string,vector<pair<string,double>>>adj;

        
        unordered_map<string,bool>vis;
        for(int i = 0; i < equations.size(); i++){

            string to = equations[i][1];
            string from = equations[i][0];

            adj[from].push_back({to,values[i]});

            adj[to].push_back({from,(1.0/values[i])});

            vis[from] = false;
            vis[to] = false;
        }

        vector<double>ans;
        // run over queries and do dfs

        for(int i = 0; i < queries.size(); i++){
            
            double value = 1.0;
            bool reached = false;

            string src = queries[i][0];
            string dest = queries[i][1];



            dfs(adj,vis,src,dest,1.0,value,reached);
            
            cout<<src<<" "<<dest<<" "<<reached<<" "<<value<<" ";
            if(reached){
            ans.push_back(value);
            }
            else{ ans.push_back(-1.0);}
            cout<<ans.back()<<endl;


        }

        return ans;

    }
};