class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        
        int xorval=0;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int x=nums[i],y=nums[j];
                if(abs(x-y)<=min(x,y)){
                    int temp=x^y;
                    xorval=max(xorval,temp);
                }
            }
        }
        return xorval;
    }
};