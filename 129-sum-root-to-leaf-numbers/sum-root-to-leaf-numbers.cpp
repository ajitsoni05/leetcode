/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<string>& nums, string num) {
        if (!root) {

            return;
        }

        num += to_string(root->val);

        if (!root->left && !root->right) {
            nums.push_back(num); // Only add when it's a leaf
            return;
        }
        dfs(root->left, nums, num);
        dfs(root->right, nums, num);
    }
    int sumNumbers(TreeNode* root) {
        vector<string> nums;
        string st = "";
        dfs(root, nums, st);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans += stoi(nums[i]);

        return ans;
    }
};