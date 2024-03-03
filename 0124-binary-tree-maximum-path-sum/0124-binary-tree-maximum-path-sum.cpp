/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPath(TreeNode*root,int& maxi){
        if(!root)return 0;
        
         int leftsum=max(0,maxPath(root->left,maxi));
         int rightsum=max(0,maxPath(root->right,maxi));
        
        maxi=max(maxi,root->val+leftsum+rightsum);
        
        return root->val+max(leftsum,rightsum);

    }
    int maxPathSum(TreeNode* root) {
        int maxi=root->val;
        if(!root->left&&!root->right)return root->val;
        maxPath(root,maxi);
        maxPath(root->left,maxi);
        maxPath(root->right,maxi);
        return maxi;
    }
};