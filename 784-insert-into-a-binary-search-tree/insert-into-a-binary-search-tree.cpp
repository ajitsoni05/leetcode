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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // insert into BST
        if(!root)return new TreeNode(val);

        


      if(root->val > val)root->left = insertIntoBST(root->left,val);
       else root->right =  insertIntoBST(root->right,val);
       TreeNode* to = new TreeNode(val);

        if(root and !root->left and !root->right){
            if(root->val >val){
                root->left = to;
            }else{
                root->right = to;
            }
            return root;
        }
    
        return root;
    }
};