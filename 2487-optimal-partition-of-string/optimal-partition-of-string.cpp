class Solution {
public:
    int partitionString(string s) {
        /*
        */

        // int len = s.size();
        // int count = 0;
        // unordered_map<int,int> tracker;


        // tracker[s[0]]++;
        
        // for(int i = 1; i < len; i++){
        //     if(tracker.count(s[i])){
        //         tracker.clear();
        //         count++;
        //     }
        //     tracker[s[i]]++;
        // }
        // return count+1;

        // alternatively  we can do it using lastSeenArray

        vector<int>lastSeen(26,-1);
        int currStartingIndex = 0;
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            if(lastSeen[s[i] - 'a'] >= currStartingIndex){
                count++;
                
                currStartingIndex = i;
            }
            lastSeen[s[i] - 'a'] = i;
        }
        return count+1;
        
    }
};