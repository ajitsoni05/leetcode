/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* prev;
    TreeNode* inorderSuccessorNode;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // check if root is NULL
        if (!root)
            return NULL;

        // Case 1: check if p has right child
        TreeNode* temp = p;
        if (p and p->right) {
            temp = p->right;
            while (temp->left) {
                temp = temp->left;
            }

            if (temp)return temp;
        }

        inorderSuccessorNode = NULL;
        // Case 2: if p has no right child
        inorder(root,p);

        return inorderSuccessorNode;


    }

    void inorder(TreeNode* node,TreeNode* p){
        if(!node)return;


        inorder(node->left,p);

        if(prev == p and inorderSuccessorNode == nullptr){
            inorderSuccessorNode = node;
            return ;
        }
        
        prev = node;
        inorder(node->right,p);
    }
};