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
    TreeNode* leastCommonAncestor(TreeNode*&root,int& startValue,int& destValue){
        if(!root)return NULL;
        if(root->val == startValue || root->val == destValue) return root;

        TreeNode* leftAns = leastCommonAncestor(root->left,startValue,destValue);
        TreeNode* rightAns = leastCommonAncestor(root->right,startValue,destValue);

       if(leftAns and rightAns) return root;
       else if(leftAns) return leftAns;
       else return rightAns;
    }
    void findPath1(TreeNode*&lca,int& startValue,string&result,string& current){
        if(!lca || !result.empty())return;

        if(lca->val == startValue){
            result = current;
            return;
        } 
        current += 'U';
        findPath1(lca->left,startValue,result,current);
        current = current.substr(0,current.size()-1);
        current+= 'U';
        findPath1(lca->right,startValue,result,current);
        current = current.substr(0,current.size()-1);
    }
    void findPath2(TreeNode*&lca,int& destValue, string&result,string& current){
           if(!lca || !result.empty())return;

        if(lca->val == destValue){
            result = current;
            return;
        } 
        current.push_back('L');
        findPath2(lca->left,destValue,result,current);
        current.pop_back();
        current.push_back('R');
        findPath2(lca->right,destValue,result,current);
        current.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        /*
        
            Approach 2:

            FIND LCA between startValue and destValue

            path b/w LCA to startValue will only have UUU...
            
            so check the path b/w LCA to destValue and backtrack while finding


            leastCommonAncestor(startValue, destValue)
            
            pathToStart and pathToDest

            findPath to determine above two

            directions = pathToStart

            directions += pathToDest


        
        */

        // lets' find LCA
        TreeNode* lcaNode = leastCommonAncestor(root,startValue,destValue);


        // findPath b/w startNode and lcaNode
        string destPath ="";
        string current = "";
        findPath1(lcaNode,startValue,destPath,current);

        string endPath = "";
        current = "";
        findPath2(lcaNode,destValue,endPath,current);

        destPath += endPath;

        return destPath;
    }
};