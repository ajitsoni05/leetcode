class Solution {
public:
    string solve(string rle){
        string ans="";
        string num=rle;
        int iter=0;
        char curchar=num[0];
        int cnt=0;
        while(iter<num.size()){
            if(num[iter]==curchar){
                cnt++;
            }else{
                ans+=to_string(cnt)+curchar;
                cnt=1;
                curchar=num[iter];
            }
            iter++;
        }
        ans+=to_string(cnt)+curchar;
        return ans;
    }
    string countAndSay(int n) {
        if(n==1)return "1";
        string rle="1";
        for(int i=2;i<=n;i++){
            rle=solve(rle);
        }
        return rle;
    }
};