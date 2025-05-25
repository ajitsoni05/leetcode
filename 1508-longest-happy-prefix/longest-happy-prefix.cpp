class Solution {
public:
    string longestPrefix(string s) {
        // kmp algorithm

        int n = s.size(); // length of string

        // make an array
        vector<int> vec(n, 0);

        // use two pointers i j
        int j = 0, i = 1;

        while (i < n) {
            if (s[j] == s[i]) {
                vec[i] = j + 1;
                j++;
                i++;
            } else {
                if (j > 0) {
                    j = vec[j - 1]; // backtrack j
                } else {
                    vec[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(0, vec[n - 1]);
    }
};