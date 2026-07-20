class Solution {
public:
    string s,p;
    map<pair<int,int>,bool>memo;
    bool recurse(int i, int j){
        if(memo.count({i,j}))return  memo[{i,j}];
        if(i >= s.size() and j >= p.size()){
            memo[{i,j}] = true;
            return  memo[{i,j}];
        }else if(j >= p.size()){
             memo[{i,j}] = false;
             return  memo[{i,j}];
        }

        bool currentMatch = (i < s.size() and ((s[i] == p[j])or p[j]=='.'));

        if(currentMatch){
            if(j+1 < p.size() and p[j+1] == '*'){
                 memo[{i,j}] =  recurse(i+1,j) || recurse(i,j+2);
                 return  memo[{i,j}];
            }else{
                 memo[{i,j}] =  recurse(i+1,j+1);
                 return  memo[{i,j}];
            }
        }else{
            if(j+1 < p.size() and p[j+1] == '*'){
                 memo[{i,j}] = recurse(i,j+2);
                 return  memo[{i,j}];
            }
        }

         memo[{i,j}] = false;
        return  memo[{i,j}];
    }
    bool isMatch(string s, string p) {
        /*

            s = "aa"
            p = "a*"

                a*

        (i+1,j)         (i,j+2)
         a              ""
        
        
        i >= s.size() and j >= p.size() return true
        if(j >= p.size()) return false

        */
        this->s = s;
        this->p = p;
        return recurse(0,0);
    }
};