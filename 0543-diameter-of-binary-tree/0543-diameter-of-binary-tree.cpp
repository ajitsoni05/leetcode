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
    int h(TreeNode*root){
        if(!root)return 0;
        int l=h(root->left);
        int r=h(root->right);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int lh=h(root->left);
        int rh=h(root->right);
        int a=diameterOfBinaryTree(root->left);
        int b=diameterOfBinaryTree(root->right);
        return max(a,max(b,(lh+rh)));
    }
};