class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // make graph
        unordered_map<int,vector<pair<int,int>>>g;
        // visited set
        set<int>visited;
        
        // constructing graph
        for(int i=0;i<times.size();i++){
            g[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        
        int t=0;
        
        while(!pq.empty()){
            
            pair<int,int>p=pq.top();
            pq.pop();
            
            if(visited.find(p.second)!=visited.end())continue;
            visited.insert(p.second);
             
            t=max(t,p.first);
            
            for(auto nb: g[p.second]){
                if(visited.find(nb.first)==visited.end()){
                    pq.push({nb.second+p.first,nb.first});
                }
            }
        }

        return visited.size()==n?t:-1;
    }
};