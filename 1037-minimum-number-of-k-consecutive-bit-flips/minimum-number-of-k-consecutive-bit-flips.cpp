class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<bool>flipped(nums.size(),false);
        int validFlipsFromPastWindow = 0;
        int flipsCount = 0;

        for(int i = 0; i < nums.size(); i++){
           int num = nums[i];

           if(i >= k){
            if(flipped[i-k]){
                validFlipsFromPastWindow--;
            }
           }

           if(validFlipsFromPastWindow % 2 == num){

            if(i + k > nums.size())return -1;

            validFlipsFromPastWindow++;
            flipped[i] = true;
            flipsCount++;
           }
        }
        return flipsCount;
    }
};