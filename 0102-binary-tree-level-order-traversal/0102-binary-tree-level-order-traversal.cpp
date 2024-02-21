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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(!root)return ans;
        
        
        queue<TreeNode*>q;
        q.push(root);
        
        
        
        while(!q.empty()){
            vector<int>level;
            
            int l=q.size();
            
            for(int i=0;i<l;i++){
                TreeNode*currentNode=q.front();
                q.pop();
                
                level.push_back(currentNode->val);
                
                if(currentNode->left)q.push(currentNode->left);
                if(currentNode->right)q.push(currentNode->right);
                
            }
            ans.push_back(level);
            
            
        }
        
        return ans;
    }
};