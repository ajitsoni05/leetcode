class Solution {
public:
    bool isSubsequence(string s, string a) {
        if (s.size() > a.size())
            return false;

        int ptrA = 0;
        int ptrS = 0;

        while (ptrS < s.size() && ptrA < a.size()) {
            if (s[ptrS] == a[ptrA])
                ptrS++;
            ptrA++;
        }

        if (ptrS == s.size())
            return true;

        return false;
    }
    int findLUSlength(vector<string>& strs) {
        // check full string, if is prefix
        int n = strs.size();
        int minLen = 0;

        for (int i = 0; i < n; i++) {
            bool isCand = true;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (isSubsequence(strs[i], strs[j])) {
                    isCand = false;
                    break;
                }
            }
            if (isCand) {
                minLen = max(minLen, (int)strs[i].size());
            }
        }
        return minLen ? minLen : -1;
    }
};