class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt_o=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                s=s.substr(0,i)+s.substr(i+1,n);
                break;
            }
        }
        sort(s.begin(),s.end(),greater<char>());
        return s+"1";
    }
};