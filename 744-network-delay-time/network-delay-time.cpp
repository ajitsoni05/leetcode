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
            
           auto[delay,node]=pq.top();
            pq.pop();
            
            if(visited.find(node)!=visited.end())continue;
            visited.insert(node);
             
            t=max(t,delay);
            
            for(auto [nbNode,nbDelay]: g[node]){
                if(visited.find(nbNode)==visited.end()){
                    pq.push({nbDelay+delay,nbNode});
                }
            }
        }

        return visited.size()==n?t:-1;
    }
};