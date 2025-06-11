class Solution {
public:
    // memo 
    string st;
    vector<int>memo;
    int n;
    vector<string>words;
    int dp(int idx){
        if(idx < 0)return 1;
        if(memo[idx]!=-1)return memo[idx];

        if(memo[idx]==-1){

            for(auto word:words){
                if(idx >= word.length() - 1 and dp(idx-word.length())){
                    if(st.substr(idx-word.length()+1,word.length())==word){
                        memo[idx]=1;
                    }
                }
            }

        }

        if(memo[idx]==-1)memo[idx] = 0;

        return memo[idx];


        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.size(),-1);
        n = s.size();
        words = wordDict;
        st = s;

        return dp(s.size()-1);


    }
};