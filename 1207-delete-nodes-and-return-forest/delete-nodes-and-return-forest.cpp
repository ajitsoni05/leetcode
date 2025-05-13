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
    vector<TreeNode*> saveNodes;
    unordered_map<int, int> nodesToDelete;

    void dfs(TreeNode* &root) {
        if (!root) return;

        dfs(root->left);
        dfs(root->right);

        if (nodesToDelete.count(root->val)) {
            if (root->left && !nodesToDelete.count(root->left->val)) {
                saveNodes.push_back(root->left);
            }
            if (root->right && !nodesToDelete.count(root->right->val)) {
                saveNodes.push_back(root->right);
            }
            delete root;
            root= NULL;  // delete this node
        }

        
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int val : to_delete) {
            nodesToDelete[val] = 1;
        }

        if (root && !nodesToDelete.count(root->val)) {
            saveNodes.push_back(root);
        }

        dfs(root);

        return saveNodes;
    }
};
