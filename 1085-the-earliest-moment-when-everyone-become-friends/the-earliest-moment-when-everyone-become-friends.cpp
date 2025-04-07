class Solution {
public:

    vector<int>par;
    bool join(int x,int y){
        int p1 = find(x);
        int p2 = find(y);
        if(p1 == p2) return false;
        if(p1>p2){
            par[p1]=p2;
        }else{
            par[p2]=p1;
        }
        return true;
    }
    int find(int x){
        if(par[x]!=x) par[x] = find(par[x]);
        return par[x];
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        /*

        logs i - ts , xi, yi 
        
        time when number of connected components is 1 in total and 
        there are n-1 nodes in the connected component

        - sort the logs based on increasing order of timestamps
        - have a counter cnt initially set to n
        - decrease the cnt as we get true everytime in union find
        - when cnt reaches 1 return the ts

        */ 

        sort(logs.begin(),logs.end());
        par.resize(n);

        // initialize parents

        for(int i=0;i<n;i++){
            par[i] = i;
        }

        int cnt = n;

        for(auto log:logs){
            if (join(log[1],log[2]))cnt--;
            if(cnt == 1) return log[0];
        }
        return -1;
        



    }
};