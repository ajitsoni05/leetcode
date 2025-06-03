class Solution {
public:
    void leftOvers(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*>& left, TreeNode* parent, bool isLeftChild) {
        if (!root) return;

        // Recurse first on children
        leftOvers(root->left, to_delete, left, root, true);
        leftOvers(root->right, to_delete, left, root, false);

        // If current node needs to be deleted
        if (to_delete.count(root->val)) {
            if (root->left) left.push_back(root->left);
            if (root->right) left.push_back(root->right);

            // Disconnect from parent
            if (parent) {
                if (isLeftChild) parent->left = nullptr;
                else parent->right = nullptr;
            }
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> left;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());

        // Start recursion
        leftOvers(root, to_delete_set, left, nullptr, false);

        // If root itself is not deleted, add to result
        if (!to_delete_set.count(root->val)) {
            left.push_back(root);
        }

        return left;
    }
};
