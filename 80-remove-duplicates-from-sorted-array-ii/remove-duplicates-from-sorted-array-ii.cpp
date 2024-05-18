class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
       int l=0,r=1;
       int c=0;
       unordered_map<int,int>mp;
       mp[nums[l]]++;
       while(r!=nums.size()){
        if(mp.count(nums[r])>0&&mp[nums[r]]>=2)r++;
        else{
            mp[nums[r]]++;
            swap(nums[l+1],nums[r]);
            c++;
            l++,r++;
        }
       }
       return c+1;
    }
};