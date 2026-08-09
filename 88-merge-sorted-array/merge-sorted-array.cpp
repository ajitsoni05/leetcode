class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // first write nums2 into later part ( > m) of nums1
        
        /*
        
        Simplest solution

        for(int i = 0; i < n; i++){
            nums1[i+m] = nums2[i];
        }

        // now sort
        sort(nums1.begin(),nums1.end());
        return;

        */


        
        // auxiliary space

        vector<int> merged(m+n, 0);

        int i = 0,j = 0;
        int w = 0;

        while(i < m || j < n) {

            if(i < m and j < n)
            merged[w++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
            else if(i < m)
            merged[w++] = nums1[i++];
            else
            merged[w++] = nums2[j++];
        }
        
        // rewrite merged into nums1
        for(int i = 0; i < m+n; i++){
            nums1[i] = merged[i];
        }
        


    }
};