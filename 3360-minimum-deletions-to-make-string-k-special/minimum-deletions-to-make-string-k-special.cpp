class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>charMap;


        for(int i = 0; i < word.size(); i++){
            charMap[word[i]]++;
        }


        int res = word.size();;

        for(auto it:charMap){
            // mark as lowest
            int freq = it.second;
            int del = 0;

            for(auto i = charMap.begin(); i!= charMap.end(); ++i){
                if(freq > i->second){
                    del += i->second;
                }else if(i->second > freq+k){
                    del += i->second-freq-k;
                }
            }
            res = min(res,del);
        }
        return res;
    }
};