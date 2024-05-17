class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        // adjacency list graph
        unordered_map<int,vector<pair<int,int>>>g;

        // visited set
        set<int>s;
        for(int i=0;i<points.size();i++){
          for(int j=i+1;j<points.size();j++){

            int x1=points[i][0],y1=points[i][1];
            int x2=points[j][0],y2=points[j][1];
            int dist=abs(x1-x2)+abs(y1-y2);

            g[i].push_back({j,dist});
            g[j].push_back({i,dist});

          }
        }

        // start bfs and prims

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,0});

        int ans=0;
        while(s.size()<points.size()){
            pair<int,int>ele=pq.top();

            int node=ele.second;
            int wt=ele.first;

            pq.pop();

            if(s.find(node)!=s.end())continue;
            
            ans+=wt;

            s.insert(node);



            for(auto nb: g[node]){
                if(s.find(nb.first)==s.end()){
                    pq.push({nb.second, nb.first});
                }else continue;
            }
            
        }
        return ans;
    }
};