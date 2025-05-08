class Solution {
public:
    bool horizontal(vector<vector<int>>& matrix,int x,int y,int t){
        auto it = lower_bound(matrix[x].begin()+y,matrix[x].end(),t);
        return (it != matrix[x].end() && *it ==t);
    }
    bool vertical(vector<vector<int>>& matrix,int x,int y,int t){

        int l = x;
        int h = matrix.size()-1;
        while(l<=h){
            int mid = (l+h)/2;

            if(matrix[mid][y]==t)return true;
            else if(matrix[mid][y]<t)l=mid+1;
            else h = mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0,c=0;
        int m = matrix.size();
        int n = matrix[0].size();

        for(;r<m and c<n;r++,c++){
            if(horizontal(matrix,r,c,target)||vertical(matrix,r,c,target))return true;
        }
        return false;
    }
};