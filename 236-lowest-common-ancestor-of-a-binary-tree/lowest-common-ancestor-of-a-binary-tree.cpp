/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // dfs
        if(!root) return root;
        if(root == p)return p;
        if(root == q)return q;

        // lets make parent map
        unordered_map<TreeNode*,TreeNode*>parent;
        parent[root] = nullptr;

        // queue for traversal
        queue<TreeNode*>qNodes;
        
        // push root
        qNodes.push(root);

        while(!parent.count(p) || !parent.count(q)){
            TreeNode* node = qNodes.front();
            qNodes.pop();

            if(node->left){
                parent[node->left]= node;
                qNodes.push(node->left);
            }

            if(node->right){
                parent[node->right]= node;
                qNodes.push(node->right);
            }

        }

        // gather ancestors
        unordered_set<TreeNode*>ancestors;

        while(p){
            ancestors.insert(p);
            p = parent[p];
        }

        while(ancestors.find(q) == ancestors.end()){
            q = parent[q];
        }

        return q;
    }
};