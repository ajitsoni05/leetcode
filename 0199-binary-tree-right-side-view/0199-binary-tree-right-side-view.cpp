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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return{};
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int l=q.size();
            
            for(int i=0;i<l;i++){
                
                TreeNode*currentNode=q.front();
                q.pop();
                
                if(i==l-1)ans.push_back(currentNode->val);
                
                if(currentNode->left)q.push(currentNode->left);
                if(currentNode->right)q.push(currentNode->right);
                
                
            }
        }
        return ans;
        
        
        
    }
};