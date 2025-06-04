class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0] == 0 ? -1 : 1;

        sort(nums.begin(),nums.end());

        // int iterator
        int x = 0;
        
        while(x <= n){
            auto it = lower_bound(nums.begin(),nums.end(),x);

            if(nums.end()-it == x )return x;
            x++;
        }
        return -1;
    }
};