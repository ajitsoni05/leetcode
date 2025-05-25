class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // build kmp array
        vector<int>kmp(s.size(),0);

        // iterators i and j
        int j = 0, i = 1;

        int n = s.size();

        while(i < n){
            if(s[i]==s[j]){
                kmp[i] = j+1;
                j++;
                i++;
            }else{
                if(j > 0){
                    j = kmp[j-1];
                }else{
                    kmp[i] = 0;
                    i++;
                }
            }
        }
    
        int len = kmp[n-1];
        return len > 0 && n % (n - len) == 0;    
    }
};