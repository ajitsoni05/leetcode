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
    void preT(TreeNode* root,vector<TreeNode*>&pre){
        if(!root){
            return;
        }
        pre.push_back(root);

        preT(root->left,pre);
        preT(root->right,pre);

        
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> pre;
        preT(root,pre);
        // 
        TreeNode* tempR = new TreeNode();
        if(pre.size()){
        tempR= pre[0];
        TreeNode* temp = tempR;
        for(int i=0;i<pre.size()-1;i++){
            TreeNode* t = temp;
            t->left = NULL;
            t->right = pre[i+1];
            temp = temp->right;


        }
        root = tempR->right; 
        }   


    }
};