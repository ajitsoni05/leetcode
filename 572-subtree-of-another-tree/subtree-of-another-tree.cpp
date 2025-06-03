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
    bool isSame(TreeNode*root1, TreeNode*root2){
        if(!root1 and !root2)return true;
        else if(!root1 || !root2)return false;
         bool l =  isSame(root1->left,root2->left);
         bool r =  isSame(root1->right,root2->right);

         return root1->val == root2->val and l and r;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot)return true;
        if(!root || !subRoot)return false;
        bool a =  isSame(root,subRoot) || isSame(root->left,subRoot) || isSame(root->right,subRoot);

        return a || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};