class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num==0)return true;
        if(num%10==0)return false;
        string s=to_string(num);
        string r1=s;
        reverse(r1.begin(),r1.end());
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(r1[i]=='0')continue;
            else{
                idx=i;
                break;
            }
        }
        r1=r1.substr(idx);
        string r2=r1;
        reverse(r2.begin(),r2.end());
        if(s==r2)return true;
        return false;
    }
};