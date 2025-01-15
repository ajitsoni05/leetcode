class Solution {
public:
    int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) {
        if(nums1==nums2)return nums1.size();
        int rsmax = nums1.size()-1;
        int maxMatches =0;
        for(int shift=0;shift<=rsmax;shift++){
            int matchCount =0;
            for(int i=0;i<nums1.size();i++){
                int idx = i;
                int newIdx = (idx+shift)%(rsmax+1);
                if(nums2[newIdx]==nums1[i]){
                    matchCount++;
                }
                maxMatches= max(maxMatches,matchCount);
            }
        }
        return maxMatches;
    }
};