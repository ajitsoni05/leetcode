class Solution {
public:
    int possibleStringCount(string word) {

        if(word.size() == 1) return word.size();

        int n = word.size();

        vector<int>multi_freq;
        
        char c = word[0];
        int cur_freq = 1;
        for(int i = 1; i < n; i++){
            if(word[i] == c){
                cur_freq++;
            }else{
                if(cur_freq > 1){
                    multi_freq.push_back(cur_freq-1);
                }
                cur_freq = 1;
                c = word[i];
            }
        }

        if(cur_freq > 1){
            multi_freq.push_back(cur_freq-1);
        }

        int ans = accumulate(multi_freq.begin(),multi_freq.end(),0);

        return ans+1;
    }
};