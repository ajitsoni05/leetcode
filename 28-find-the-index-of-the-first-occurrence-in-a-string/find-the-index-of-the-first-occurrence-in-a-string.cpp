class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;

        vector<int> kmp(needle.size(), 0);
        int j = 0, i = 1;
        int n = needle.size();

        while (i < n) {
            if (needle[j] == needle[i]) {
                kmp[i] = j + 1;
                j++;
                i++;
            } else {
                if (j > 0) {
                    j = kmp[j - 1];
                } else {
                    i++;
                }
            }
        }

        int m = haystack.size();
        i = 0;
        j = 0;
        while(i< m){
            if(haystack[i]==needle[j]){

                if(j == n-1)return i-n+1;
                i++;
                j++;
            }else{
                if(j > 0){
                    j = kmp[j-1];
                }else{
                    i++;
                }
            }
        }

        return -1;
    }
};
