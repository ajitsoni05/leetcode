class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>numFreq;

        for(int i = 0; i < nums.size(); i++)numFreq[nums[i]]++;

        int max_count = 0;
        int curr = 0;
        int curr_num = INT_MIN;
        
        for(auto it:numFreq){
            if(curr_num == INT_MIN){
                curr_num = it.first;
                curr = it.second;
            }else if(curr_num == it.first - 1){
                curr += it.second;
                max_count = max(max_count,curr);
                curr_num = it.first;
                curr = it.second;
            }else{
                  curr_num = it.first;
                curr = it.second;
            }
        }
        return max_count;
    }
};