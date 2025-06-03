class Solution {
public:
    unordered_set<int> to_delete_set;
    vector<TreeNode*> forest;

    TreeNode* helper(TreeNode* root) {
        if (!root) return nullptr;

        root->left = helper(root->left);
        root->right = helper(root->right);

        if (to_delete_set.count(root->val)) {
            if (root->left) forest.push_back(root->left);
            if (root->right) forest.push_back(root->right);
            return nullptr; // delete current node
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        to_delete_set = unordered_set<int>(to_delete.begin(), to_delete.end());

        if (!to_delete_set.count(root->val)) {
            forest.push_back(root);
        }

        helper(root);
        return forest;
    }
};
