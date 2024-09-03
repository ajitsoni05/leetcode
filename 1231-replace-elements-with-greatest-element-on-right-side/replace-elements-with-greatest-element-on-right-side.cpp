class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // replace every element with greatest element on right
        int n=arr.size();
        vector<int>ans(n,0);
        ans[n-1]=-1;

        int gt=arr[n-1];

        for(int i=n-2;i>=0;i--){
            ans[i]=gt;       
            if(arr[i]>gt)gt=arr[i];
        }

        return ans;

    }
};