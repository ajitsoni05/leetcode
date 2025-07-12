class Solution {
public:
    int getLeastLastIndex(unordered_map<char,int>&lastIndex){
        int minm = INT_MAX;

        for(auto ele: lastIndex){
            minm = min(minm,ele.second);
        }
        return minm;
    }
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int l = 0,r = 0;
        int n = s.size();

        int cur_size = 0;

        // leastIndex
        unordered_map<char,int>lastIndex;

        int maxLen = 0;

        while(r < n) {
            char ch = s[r];
            if(cur_size < 2){ if(!lastIndex.count(ch))cur_size++;  lastIndex[ch] = r;}
            else {
                if(lastIndex.count(ch))lastIndex[ch] = r;
                else{
                    int leastIndex = getLeastLastIndex(lastIndex); 
                    char toRemove = s[leastIndex];
                    lastIndex.erase(toRemove);
                    cur_size--;
                    l = leastIndex + 1;
                    lastIndex[ch] = r;
                    cur_size++;
                }
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};