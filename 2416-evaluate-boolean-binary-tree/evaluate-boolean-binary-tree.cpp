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
    bool evaluateTree(TreeNode* root) {
        if(!root)return false;
        
        bool a = evaluateTree(root->left);
        bool b = evaluateTree(root->right);

        if(root and root->left){
            if(root->val == 2){
                return a or b;

            }else if(root->val ==3){

                return a and b;

            }
        }else if(!root->left){
            return root->val;
        }

        return 0;

        
    }
};