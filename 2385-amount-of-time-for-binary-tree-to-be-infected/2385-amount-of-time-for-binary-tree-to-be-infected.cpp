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
    void makeGraph(unordered_map<int,vector<int>>&g,TreeNode* root){
        if(!root)return;
        if(root->left){
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
        }
        if(root->right){
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
        }
        makeGraph(g,root->left);
        makeGraph(g,root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        // Traverse the tree and make a graph
        unordered_map<int,vector<int>>g;

        makeGraph(g,root);
        set<int>visited;

        // Apply bfs and see time
        int t=0;
        queue<pair<int,int>>q;
        q.push({start,0});
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int node=p.first;
            int time=p.second;
            if(visited.find(node)!=visited.end())continue;

            visited.insert(node);
            t=max(t,time);

            for(auto nb:g[node]){
                if(visited.find(nb)==visited.end()){
                    q.push({nb,time+1});
                }else continue;
            }
        }
        return t;
    }
};