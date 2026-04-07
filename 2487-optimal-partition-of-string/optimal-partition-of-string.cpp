class Solution {
public:
    int partitionString(string s) {
        /*
        */

        int len = s.size();
        int count = 0;
        unordered_map<int,int> tracker;


        tracker[s[0]]++;
        for(int i = 1; i < len; i++){
            if(tracker.count(s[i])){
                tracker.clear();
                count++;
            }
            tracker[s[i]]++;
        }
        return count+1;
        
    }
};