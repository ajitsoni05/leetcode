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
    int widthOfBinaryTree(TreeNode* root) {
         
        // do a level order traversal and subtract the indexes of last available node - first available node
        // in the binary tree
        if(root==NULL)return 0;
        queue<pair<TreeNode*,long long>>q;
        int maxwidth=1;
        q.push({root,1});
        
        while(!q.empty()){
            int level=q.size();
            int first;
            int last;
            long long mmin=q.front().second;
            for(int i=0;i<level;i++){
                TreeNode*temp=q.front().first;
                long long idx=q.front().second-mmin;
                q.pop();
                if(i==0)first=idx;
                if(i==level-1)last=idx;
                if(temp->left)q.push({temp->left,(long long)(2*(idx-1)+1)});
                if(temp->right)q.push({temp->right,(long long )(2*(idx-1)+2)});
            }
            maxwidth=max(maxwidth,(last-first+1));
          
            
        }
          return maxwidth;
    }
};