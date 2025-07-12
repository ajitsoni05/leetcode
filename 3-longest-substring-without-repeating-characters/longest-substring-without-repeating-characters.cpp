class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;

        unordered_map<char,int>lastIndex;

        int n = s.size();

        int maxLen = 0;


        while(r < n){
            if(lastIndex.count(s[r]) and lastIndex[s[r]] >= l)
            {
                l = lastIndex[s[r]] + 1;
            }
            lastIndex[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};