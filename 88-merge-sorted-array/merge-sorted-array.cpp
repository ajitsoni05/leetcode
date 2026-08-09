class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // first write nums2 into later part ( > m) of nums1

        for(int i = 0; i < n; i++){
            nums1[i+m] = nums2[i];
        }

        // now sort
        sort(nums1.begin(),nums1.end());
        return;

    }
};