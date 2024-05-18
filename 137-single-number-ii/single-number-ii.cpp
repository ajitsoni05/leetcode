class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // bitwise nums

        vector<int>bits(32,0);

        for(int i=0;i<nums.size();i++){
            int num=nums[i];

            for(int j=31;j>=0;j--){
                if(num&(1<<j))
                bits[j]++;
            }
        }
        int num=0;
        for(int i=0;i<bits.size();i++){
            if(bits[i]%3){
                num|=(1<<i);
            }
        }
        return num;
    }
};