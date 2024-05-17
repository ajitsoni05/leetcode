class Solution {
public:

    void dfs(unordered_map<int,vector<int>>&g,int src,int& lq,int&lqp, vector<int>& quiet,set<int>&v){
        v.insert(src);
        if(lq>quiet[src]){
            lq=quiet[src];
            lqp=src;
        }
        for(auto nb: g[src]){
            if(v.find(nb)==v.end())
            dfs(g,nb,lq,lqp,quiet,v);
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        

        // construct a directed graph using adjacency list 

        // for each node traverse the graph starting the node as the source

        // and while traversal track the least quiet

        unordered_map<int,vector<int>>g;

        vector<int>ans;

        for(int i=0;i<richer.size();i++){
            g[richer[i][1]].push_back(richer[i][0]);
        }

        for(int i=0;i<quiet.size();i++){
            int lq=quiet[i];
            int lqp=i;
            set<int>v;
            dfs(g,i,lq,lqp,quiet,v);
            ans.push_back(lqp);
        }
        return ans;


    }
};