class Solution {
public:
    int find(int node, vector<int>&par){
        while(par[node]!=node){
            node=par[node];
        }
        return node;
    }
    bool unionFind(int n1,int n2, vector<int>&par,vector<int>&rk){
        int p1=find(n1,par);
        int p2=find(n2,par);
        if(p1==p2)return true;
        else{
            if(rk[p1]>rk[p2]){
                rk[p1]+=rk[p2];
                par[p2]=p1;
            }else{
                rk[p2]+=rk[p1];
                par[p1]=p2;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        // parent array
        vector<int>par(n);
        
        // rank array 
        vector<int>rk(n,1);
        
        //init par
        for(int i=0;i<n;i++){par[i]=i;}
        
        //traverse edges
        for(auto edge:edges){
            //union find
            int n1=edge[0]-1;
            int n2=edge[1]-1;
            if(unionFind(n1,n2,par,rk))return{n1+1,n2+1};
        }
        
        
        return {};
    }
};