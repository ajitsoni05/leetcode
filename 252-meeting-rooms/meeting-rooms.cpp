class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int score = 0;

        map<int,int>sweep;

        for(auto interval:intervals){
            sweep[interval[0]]++;
            sweep[interval[1]]--;
        }


        int rolling_sum = 0;

        for(auto ele:sweep){
            rolling_sum += ele.second;

            if(rolling_sum > 1)return false;
        }
        return true;
    }
};