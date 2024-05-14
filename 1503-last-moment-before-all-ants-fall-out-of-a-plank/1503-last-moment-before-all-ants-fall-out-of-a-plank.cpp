class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        if(left.size())ans=max(ans,*max_element(left.begin(),left.end()));
        if(right.size())ans=max(ans,n-*min_element(right.begin(),right.end()));
        
        return ans;
    }
};