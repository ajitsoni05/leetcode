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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        /*
            auto leftChild = root->left
            auto rightChild = root->right
            auto originalRoot = root

            

            upSideDownBinaryTree(leftChild)
            if(!root) return null;

            root->left = null;
            root->right = null;

            leftChild->left rightChild
            leftChild->right = root

            
            return leftChild
        */

            if(!root) return nullptr;
            if(!root->left) return root;

            
            auto leftChild = root->left;
            auto rightChild = root->right;
            auto originalRoot = root;

            auto newRoot = upsideDownBinaryTree(leftChild);

            leftChild->left = rightChild;
            leftChild->right = root;
            root->left = nullptr;
            root->right = nullptr;
            return newRoot;


        

    }
};