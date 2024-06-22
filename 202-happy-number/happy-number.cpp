class Solution {
public:
    int compute(int n){
        string num=to_string(n);
        
        int ans=0;

        for(int i=0;i<num.size();i++){
            ans+=(num[i]-'0')*(num[i]-'0');
        }
        return ans;
    }
    bool isHappy(int n) {
        
        set<int>s;
        while(compute(n)!=1){
            int s1=s.size();
            s.insert(compute(n));
            int s2=s.size();
            if(s1==s2)return false;
            n=compute(n);
        }
        return true;
    }
};