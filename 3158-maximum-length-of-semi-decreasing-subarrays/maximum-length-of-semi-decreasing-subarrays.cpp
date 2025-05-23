class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(st.empty() || nums[st.top()] < nums[i]) st.push(i);
        }
        // push the indexes into stack untill the nums[i] < nums[st.top()]
        // 7 10 11
        

        int ans = 0;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                ans = max(ans, i-st.top()+1);
                st.pop();
            }
        }
        return ans;
    }
};