/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (71.07%)
 * Likes:    6287
 * Dislikes: 257
 * Total Accepted:    572.5K
 * Total Submissions: 804.6K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate an n x n matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        

        // initialize the ans matrix
        vector<vector<int>> ans(n,vector<int>(n,0));

        // initialize 4 pointers
        int l=0,r=n-1,u=0,d=n-1;

        int count=1;

        while(l<=r && u<=d){

            for(int j=l;j<=r;j++){
                ans[u][j]=count;
                count++;
            }
             u++;
            for(int i=u;i<=d;i++){
                ans[i][r]=count;
                count++;
            }
            r--;
            for(int j=r;j>=l;j--){
                ans[d][j]=count;
                count++;
            }
            d--;
            for(int i=d;i>=u;i--){
                ans[i][l]=count;
                count++;
            }
            l++;
    
        }
        return ans;
       
        

    }
};
// @lc code=end

