class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int first =0;
        int n = nums.size();

        int num = INT_MIN;

        int count =0;
        for(int i=0;i<n;i++){
            if(nums[i]==num)continue;
            else{
                nums[first++]=nums[i];
                num = nums[i];
                count++;
            }
        }
        return count;
    }
};