class Solution {
public:
    map<pair<int,int>,int>memo;
    void editDistance(const string& s,const string& t,int s_i,int t_i,int curr_dist,int& ans){
        if(curr_dist > 1)return;
        if(memo.count({s_i,t_i}) and memo[{s_i,t_i}] <= curr_dist)return;
        if(s_i == s.size() && t_i == t.size()){
            ans = min(ans ,curr_dist);
            return;
        } 

        if(s_i >= s.size()){ ans  = min(ans,(curr_dist + (int)t.size()-t_i)); return;}
        if(t_i >= t.size()){ ans = min(ans,(curr_dist + (int)s.size()-s_i)); return;}

        if(s[s_i] == t[t_i]){
            editDistance(s,t,s_i+1,t_i+1,curr_dist,ans);
        }else{
            editDistance(s,t,s_i+1,t_i,curr_dist+1,ans);
            editDistance(s,t,s_i,t_i+1,curr_dist+1,ans);
            editDistance(s,t,s_i+1,t_i+1,curr_dist+1,ans);
        }
        memo[{s_i,t_i}] = ans;

    }
    bool isOneEditDistance(string s, string t) {
        int ans = INT_MAX;
        editDistance(s,t,0,0,0,ans);

        return ans == 1;
        
    }
};