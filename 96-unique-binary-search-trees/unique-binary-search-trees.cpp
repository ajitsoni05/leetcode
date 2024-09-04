class Solution {
public:
    int catalan_num(int n){
        if(n==0 || n==1)return 1;

        int result =0;
        for(int i=0;i<n;i++){
            result+=catalan_num(i)*catalan_num(n-i-1);
        }
        return result;
    }
    int numTrees(int n) {
        // Structurally unique binary search trees
        // having exactly n nodes 
        // This will be done using catalan num concept
        return catalan_num(n);
    }
};