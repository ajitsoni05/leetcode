class Solution {
public:
    int reverse(int x) {
        string s=to_string(x);
        string neg=to_string(INT_MIN);
        neg=neg.substr(1);
        string pos=to_string(INT_MAX);
        if(s[0]=='-'){
            s=s.substr(1);
            s.resize(pos.size(),'0');
            std::reverse(s.begin(),s.end());
            if(s>neg)return 0;
            else {
                s='-'+s;
                return stoi(s);
            }
        }else{
            s.resize(pos.size(),'0');
            std::reverse(s.begin(),s.end());
            if(s>pos)return 0;
            else return stoi(s);
        }
        return 0;
    }
};