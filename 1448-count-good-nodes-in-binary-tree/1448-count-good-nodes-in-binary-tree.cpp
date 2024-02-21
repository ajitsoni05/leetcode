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
    int Travel(TreeNode*root,int maximumValue){
        if(!root)return 0;
        if(root->val>=maximumValue){
            return 1+Travel(root->left,root->val)+Travel(root->right,root->val);
        }else{
           return Travel(root->left,maximumValue)+Travel(root->right,maximumValue); 
        }
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;
        return Travel(root,root->val);
    }
};