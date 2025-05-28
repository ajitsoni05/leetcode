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
        int full_iter = 0;
        int sub_iter = 0;
        while(full_iter<m){
            if(haystack[full_iter]==needle[sub_iter]){

                if(sub_iter == n-1)return full_iter-n+1;
                full_iter++;
                sub_iter++;
            }else{
                if(sub_iter > 0){
                    sub_iter = kmp[sub_iter-1];
                }else{
                    full_iter++;
                }
            }
        }

        return -1;
    }
};
