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
        queue<pair<TreeNode*,int>>q;
        
        if(root==NULL)return{};
        vector<vector<int>>ans;
        q.push({root,0});
        vector<int>l;
        int curlevel=0;
        
        while(!q.empty()){
            
            TreeNode*currentNode=q.front().first;
            int level=q.front().second;
            q.pop();
           
            
           if(curlevel==level){
               l.push_back(currentNode->val);
           }else{
               ans.push_back(l);
               l.clear();
               curlevel+=1;
               l.push_back(currentNode->val);
           }
            
            
            if(currentNode->left)
            q.push({currentNode->left,level+1});
            if(currentNode->right)
            q.push({currentNode->right,level+1});
            
          
            
        }
        ans.push_back(l);
        return ans;
    }
};