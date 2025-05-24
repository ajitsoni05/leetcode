class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // using stack O(n) TC and O(n) SC
        stack<int> st;

        int l = nums.size(),r=0;

        int n = nums.size();


        for(int i = 0; i < n;i++){
            while(!st.empty() and nums[st.top()] > nums[i]){
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty())st.pop();

        for(int i = n-1; i>=0;i--){
            while(!st.empty() and nums[st.top()] < nums[i]){
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }

        return r-l+1 > 0 ? r-l+1:0;

    }
};