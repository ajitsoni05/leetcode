class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();

        if(n*k == 0)return 0;

        int left = 0, right = 0;

        unordered_map<char,int>rightMostIndex;

        int maxLen = 0;

        while(right < n){
            rightMostIndex[s[right]]++;

            while(rightMostIndex.size() > k){
                rightMostIndex[s[left]]--;
                if(rightMostIndex[s[left]] == 0)rightMostIndex.erase(s[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};