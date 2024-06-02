class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> cap;

        k=k%nums.size();
        for(int i=0;i<k;i++){
            int num=nums.back();
            cap.push_back(num);
            nums.pop_back();
        }
        reverse(nums.begin(),nums.end());
        for(int i=0;i<cap.size();i++){
            nums.push_back(cap[i]);
        }
        reverse(nums.begin(),nums.end());
    }
};