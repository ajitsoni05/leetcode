class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int mod=1e9+7;
        bool first=true;
        int count=0;
        vector<int>zeroes;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(first){
                    first=false;
                }else{
                    zeroes.push_back(count);
                }
                count=0;

            }else{
                count++;
            }
        }

        long long ans = 1;
        for (int i = 0; i < zeroes.size(); i++) {
            ans = ((ans % mod) * ((zeroes[i] + 1) % mod)) % mod;
        }
        return first?0:ans;
    }

};