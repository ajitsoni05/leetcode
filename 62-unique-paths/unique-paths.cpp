class Solution {
public: 

    int uniquePaths(int m, int n) {
        
        // nCr

        int tot=m+n-2; // 8
        int r=n-1; // 6
        double res=1; // 3/1, 4/2 , 5/3 ... 8/6

        for(int i=1;i<=r;i++){
            res=res*(tot-r+i)/(i);
        }
        return (int)res;
    }
};