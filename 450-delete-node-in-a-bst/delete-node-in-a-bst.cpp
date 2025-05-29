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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            /*
                check three conditions

                root->val and key

            */

            if(root->val > key){
                // recursively delete key from left subtree and assign left subtree
                root->left = deleteNode(root->left,key);

            }else if(root->val < key){
                // recursively delete key from right subtree and assign right subtree
                root->right = deleteNode(root->right,key);

            }else if(root->val == key) {
                /*
                    check for three conditions

                    - if root is leaft
                    - if root has either left or right but not both
                    - if root has both
                */

                if(!root->left and !root->right){
                    // simply return NULL since consider it as deleted
                    return nullptr;
                }else if(!root->left || !root->right){
                    // simply copy the non-empty node to itself
                    root = root->left ? root->left : root->right;
                }else if(root->left and root->right){
                    // check the successor of the root
                    TreeNode* successor = root->right;

                    while(successor->left)successor = successor->left;

                    // now copy this value onto root and then recursively delete successor
                    root->val = successor->val;
                    
                    root->right = deleteNode(root->right,successor->val);
                }

            }

        }

        return root;
    }
};