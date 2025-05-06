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
    vector<int> nodeValues;
    void dfs(TreeNode* root){
        if(!root)return ;

        dfs(root->left);
     
        nodeValues.push_back(root->val);

        dfs(root->right);


       
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int minm=INT_MAX;
        for(int i=0;i<nodeValues.size()-1;i++){
            cout<<nodeValues[i]<<endl;
            minm = min(minm,abs(nodeValues[i]-nodeValues[i+1]));
        }
        return minm;
        
    }
};