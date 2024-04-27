class Solution {
public:
    void dfs(unordered_map<string,vector<string>>&mp,bool&exists,string s,string d,unordered_map<string,bool>&vis){
        vis[s]=true;
        if(s==d){
            exists=true;
            return;
        }
        for(auto nb:mp[s]){
            if(!vis[nb]){
                dfs(mp,exists,nb,d,vis);
            }
        }
    }
    bool equationsPossible(vector<string>& eq) {
        // use equality signs to create graph
        // use inequality signs to tell if there is a path
        vector<pair<string,string>>ineq;

        unordered_map<string,vector<string>>mp;

        for(int i=0;i<eq.size();i++){
            string exp=eq[i];
            if(exp[1]=='!'){
                ineq.push_back({eq[i].substr(0,1),eq[i].substr(3,1)});
            }else{
                mp[eq[i].substr(0,1)].push_back(eq[i].substr(3,1));
                mp[eq[i].substr(3,1)].push_back(eq[i].substr(0,1));
            }
        }
        for(int i=0;i<ineq.size();i++){
            bool exists=false;
            unordered_map<string,bool>vis;
            dfs(mp,exists,ineq[i].first,ineq[i].second,vis);
            if(exists)return false;
        }

        return true;
    }
};