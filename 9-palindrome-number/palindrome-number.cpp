class Solution {
public:
    void getDif(int x,vector<int>&nums){
        while(x){
            nums.push_back(x%10);
            x/=10;
        }
        
    }
    bool isPalindrome(int x) {
        if(x < 0)return false;

        vector<int>nums;
        getDif(x,nums);

        vector<int>rev;
        rev.insert(rev.begin(),nums.rbegin(),nums.rend());

        return nums == rev;
    }
};