/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int h(TreeNode*root){
        if(!root)return 0;
        int l=h(root->left);
        int r=h(root->right);
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int lh=h(root->left);
        int rh=h(root->right);
        if(abs(lh-rh)>=2)return false;
        if(!isBalanced(root->left)||!isBalanced(root->right))return false;
        return true;
        
    }
};