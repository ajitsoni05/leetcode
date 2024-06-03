class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>s;

        for(auto it:nums){
            s.insert(it);
        }   

        int maxm=0;
        int cur=0;
        int num=INT_MIN;

        for(auto it:s){
            if(num==INT_MIN||it ==num+1){
                cur+=1;
            }else{
                cur=1;
            }
            maxm=max(maxm,cur);
            num=it;
        }

        return maxm;
    }
};