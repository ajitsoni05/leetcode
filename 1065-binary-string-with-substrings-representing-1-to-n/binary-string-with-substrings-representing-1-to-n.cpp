class Solution {
public:
    string getBinaryString(long long n){
        string s = "";
        int num = 0;
        while(n){
            int digit = n % 2;
            n/=2;
            s = to_string(digit) + s;
        }
        return s;
    }
    bool isSubstring(string s, string bin){
       return s.find(bin) != string::npos;
    }
    bool queryString(string s, int n) {

        for(int i = 1; i <= n; i++){
            string bin = getBinaryString(i);
            if(!isSubstring(s,bin))return false;
        }
        return true;
    }   
};