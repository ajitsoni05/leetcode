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
    TreeNode* parent = nullptr;
    TreeNode* curr = root;

    // Step 1: Find the node to delete and its parent
    while (curr && curr->val != key) {
        parent = curr;
        if (key < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (!curr) return root; // Key not found

    // Step 2: If the node has two children
    if (curr->left && curr->right) {
        // Find in-order successor (leftmost node in right subtree)
        TreeNode* succParent = curr;
        TreeNode* succ = curr->right;
        while (succ->left) {
            succParent = succ;
            succ = succ->left;
        }

        // Replace curr's value with successor's value
        curr->val = succ->val;

        // Now delete the successor node
        curr = succ;
        parent = succParent;
    }

    // Step 3: Now curr has at most one child
    TreeNode* child = curr->left ? curr->left : curr->right;

    if (!parent) {
        // Deleting root node
        return child;
    }

    if (parent->left == curr)
        parent->left = child;
    else
        parent->right = child;

    return root;
}

};