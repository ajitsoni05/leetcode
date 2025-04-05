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

    void getDetails(TreeNode*root,int& sum,int& num){
        if(!root) return;
        else{
            sum+=root->val;
            num++;
        }
        getDetails(root->left,sum,num);
        getDetails(root->right,sum,num);

    }
  
    
    int averageOfSubtree(TreeNode* root) {
        if(!root)return 0;
        int sumOfNodes=0,numOfNodes=0;
        getDetails(root,sumOfNodes,numOfNodes);
        int avg = sumOfNodes/numOfNodes;
        cout<<root->val<<" "<<avg<<endl;
        // return countNodes(root,avg);
        return (root->val == avg) + averageOfSubtree(root->left) + averageOfSubtree(root->right);
         
    }   
};                                       