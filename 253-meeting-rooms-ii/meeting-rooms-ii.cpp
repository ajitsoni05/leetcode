class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int>mp;
    
        for(auto interval:intervals){
            int start = interval[0];
            int end = interval[1];
            mp[start]++;
            mp[end]--;
        }

        int maxCount = 0;
        int curr = 0;
        
        for(auto time:mp){  
            curr+=time.second;
            maxCount= max(maxCount,curr);
        }
        return maxCount;

    }
};