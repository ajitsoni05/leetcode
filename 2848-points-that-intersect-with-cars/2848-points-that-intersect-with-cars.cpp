class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        // line sweep
        unordered_map<int,int>line;
        for(int i=0;i<nums.size();i++){
          for(int j=nums[i][0];j<=nums[i][1];j++){
              line[j]++;
          }
        }
        return line.size();
    }
};