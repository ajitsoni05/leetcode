class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1=0,x2=0;
        int s1=nums1.size(),s2=nums2.size();
        for(int i=0;i<nums1.size();i++){
            x1^=nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            x2^=nums2[i];
        }
        if(s1%2){
            if(s2%2)return x1^x2;
            else return x2;
            
        }else{
            if(s2%2)return x1;
            else return 0;
        }
        
    }
};