class DisjointSet{
  public:
    vector<int>rank,parent;
    
    DisjointSet(){
        rank.resize(26);
        parent.resize(26);
        for(int i=0;i<26;i++){
            rank[i]=i;
            parent[i]=i;
        }
    }
    
    int findUParent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findUParent(parent[u]);
    }
    void Union(int u,int v){
        int uu=findUParent(u);
        int uv=findUParent(v);
        if(uu==uv)return;
        if(rank[uu]<rank[uv]){
            parent[uv]=uu;
        }else{
            parent[uu]=uv;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // We will do this via Union Find Algorithm by Rank
        // Rank here would be determined by alphabet rank
        
        //declare a disjoint set
        DisjointSet d;
        //Make a graph
        unordered_map<int,vector<int>>g;
        
        for(int i=0;i<s1.size();i++){
            d.Union(s1[i]-'a',s2[i]-'a');
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            ans+=(char)(d.findUParent(baseStr[i]-'a')+'a');
        }
        return ans;
    }
};