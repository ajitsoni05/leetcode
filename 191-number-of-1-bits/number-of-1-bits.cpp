class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;

        for(int i=31;i>=0;i--){
            if((1<<i)&n)ans++;
        }
        return ans;
    }
};