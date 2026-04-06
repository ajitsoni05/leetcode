class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxConsecutive = 0;

        int currentConsecutive = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0){
                maxConsecutive = max(maxConsecutive, currentConsecutive);

                currentConsecutive = 0;
            }else{
                currentConsecutive++;
            }
        }
        
        maxConsecutive = max(maxConsecutive, currentConsecutive);

        return maxConsecutive;

    }
};