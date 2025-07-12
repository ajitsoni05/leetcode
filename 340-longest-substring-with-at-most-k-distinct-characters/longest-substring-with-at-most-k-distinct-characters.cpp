class Solution {
public:
    int getLeastLastIndex(unordered_map<char,int>& lastIndex) {
        int minm = INT_MAX;
        for (auto& ele : lastIndex) {
            minm = min(minm, ele.second);
        }
        return minm;
    }

    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;

        int l = 0, r = 0;
        int n = s.size();
        unordered_map<char, int> lastIndex;
        int maxLen = 0;

        while (r < n) {
            char ch = s[r];
            if (lastIndex.count(ch)) {
                lastIndex[ch] = r;
            } else if (lastIndex.size() < k) {
                lastIndex[ch] = r;
            } else {
                int leastIndex = getLeastLastIndex(lastIndex);
                char toRemove = s[leastIndex];
                lastIndex.erase(toRemove);
                l = leastIndex + 1;
                lastIndex[ch] = r;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
