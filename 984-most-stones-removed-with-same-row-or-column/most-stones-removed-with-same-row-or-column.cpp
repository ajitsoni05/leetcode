
class Solution {
public:

    void dfs(unordered_map<int,vector<int>>&g,int src,unordered_map<int,int>&vis){
        vis[src]++;
        for(auto nb:g[src]){
            if(vis.count(nb)==0){
                dfs(g,nb,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        
        // no of connected components
        unordered_map<int,vector<int>>g;
        unordered_map<int,int>vis;
        for(int i=0;i<stones.size();i++){
           pair<int,int>p={stones[i][0],stones[i][1]};
           for(int j=i+1;j<stones.size();j++){
            pair<int,int>q={stones[j][0],stones[j][1]};
            if(p.first==q.first||p.second==q.second){
                g[i].push_back(j);
                g[j].push_back(i);
            }
           }
        }   

        int ans=0;
        int prev=0;
        for(auto it:g){
            if(vis.count(it.first)==0){
                dfs(g,it.first,vis);
                int cur=vis.size();
                int inc=cur-prev;
                if(inc==1)ans+=1;
                else ans+=(inc-1);
                prev=cur; 

            }
        }
        return ans;
    }
};