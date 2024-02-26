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
    void Traverse(TreeNode*root,priority_queue<int,vector<int>,greater<int>>&pq,int k){
        if(root==NULL)return;
        Traverse(root->left,pq,k);
        if(pq.size()<k)pq.push(root->val);
        else return;
        Traverse(root->right,pq,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        Traverse(root,pq,k);
        
        while(k--)pq.pop();
        return pq.top();
        
    }
};