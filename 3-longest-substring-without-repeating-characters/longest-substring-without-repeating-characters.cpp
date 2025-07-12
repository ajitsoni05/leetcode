class Solution {
public:
    int getMaxLen(unordered_map<char, int>& leastIndex) {
        int maxm = INT_MIN;
        int minm = INT_MAX;

        for (auto& ele : leastIndex) {
            minm = min(minm, ele.second);
            maxm = max(maxm, ele.second);
        }
        return maxm - minm + 1;
    }

    void clearMap(unordered_map<char, int>& leastIndex, int minIndex) {
        vector<char> keysToRemove;
        for (auto& ele : leastIndex) {
            if (ele.second <= minIndex) {
                keysToRemove.push_back(ele.first);
            }
        }
        for (char c : keysToRemove) {
            leastIndex.erase(c);
        }
    }

    int lengthOfLongestSubstring(string s) {
        int r = 0;
        int n = s.size();
        unordered_map<char, int> leastIndex;
        int maxLen = 0;

        while (r < n) {
            char curr = s[r];
            if (leastIndex.count(curr)) {
                // Duplicate found
                maxLen = max(maxLen, getMaxLen(leastIndex));
                int minIndex = leastIndex[curr];
                clearMap(leastIndex, minIndex);
            }

            leastIndex[s[r]] = r;
            r++;

            maxLen = max(maxLen, getMaxLen(leastIndex));
        }

        return maxLen;
    }
};
