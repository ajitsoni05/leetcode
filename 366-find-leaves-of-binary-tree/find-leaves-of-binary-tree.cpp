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
    void fillLeavesIntoArray(vector<int>&leaves,TreeNode* root){
        if(root == NULL or root->val ==-1000)return;

        // leaf node case
        if((!root->left or (root->left and root->left->val==-1000)) and (!root->right or(root->right and root->right->val==-1000)))
        {
            leaves.push_back(root->val);
            // mark val as -1
            root->val = -1000;
        }

        // traverse left-subtree if exists
        if(root->left and root->left->val !=-1000)
        fillLeavesIntoArray(leaves,root->left);

        // traverse right-subtree if exists
        if(root->right and root->right->val !=-1000)
        fillLeavesIntoArray(leaves,root->right);

    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        // traverse the b-tree till the leaves , push the leaves into array
        // mark the leave nodes as -1 to indicate that they have been traversed
        
        // repeat this process until root is NUll or root->val is -1

        vector<vector<int>>ans;
        while(root!=NULL and root->val != -1000){
            vector<int>leaves;
            fillLeavesIntoArray(leaves,root);
            for(int i=0;i<leaves.size();i++)cout<<leaves[i]<<" ";
            ans.push_back(leaves);
        }

        return ans;
    }
};