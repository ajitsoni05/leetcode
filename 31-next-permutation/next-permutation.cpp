class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();
        // find the breakpoint
        int bp=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                bp=i;
                break;
            }   
        }
        if(bp==-1){
            sort(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>bp;i--){
            if(nums[bp]<nums[i]){
                swap(nums[bp],nums[i]);
                break;
            }
        }
        sort(nums.begin()+bp+1,nums.end());

    }
};