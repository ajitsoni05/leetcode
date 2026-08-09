class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's voting algo
        int current = nums[0];
        int count = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == current)count++;
            else{
                if(--count == 0){
                    current = nums[i];
                    count = 1;
                }
            }
        }
        return current;
    }
};