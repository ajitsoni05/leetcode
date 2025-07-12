class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;

        unordered_map<char,int>lastIndex;

        int n = s.size();

        int maxLen = 0;


        while(r < n){
            char ch = s[r];
            if(lastIndex.count(ch) and lastIndex[ch] >= l)
            {
                l = lastIndex[ch] + 1;
            }
            lastIndex[ch] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};