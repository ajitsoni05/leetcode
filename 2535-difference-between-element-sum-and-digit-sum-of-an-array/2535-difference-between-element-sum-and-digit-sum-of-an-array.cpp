class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        
        int di_s=0;
        int el_s=0;
        
        for(int i=0;i<nums.size();i++){
            el_s+=nums[i];
            int num=nums[i];
            while(num!=0){
                di_s+=(num%10);
                num/=10;
            }
        }
        return abs(di_s-el_s);
    }
};