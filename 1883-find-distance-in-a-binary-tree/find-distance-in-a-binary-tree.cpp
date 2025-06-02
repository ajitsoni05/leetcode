class Solution {
public:
    int findDistance(TreeNode* root, int p, int l) {
        // BFS to populate parent mapping
        unordered_map<int, int> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root->val] = -1;

        bool foundp = false, foundl = false;

        while (!q.empty() && (!foundp || !foundl)) {
            TreeNode* node = q.front(); q.pop();
            if (node->val == p) foundp = true;
            if (node->val == l) foundl = true;

            if (node->left) {
                parent[node->left->val] = node->val;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right->val] = node->val;
                q.push(node->right);
            }
        }

        // Track distance from p to root
        unordered_map<int, int> distFromP;
        int curr = p, dist = 0;
        while (curr != -1) {
            distFromP[curr] = dist++;
            curr = parent[curr];
        }

        // Go from l upward, find LCA
        curr = l;
        dist = 0;
        while (distFromP.count(curr) == 0) {
            curr = parent[curr];
            dist++;
        }

        // LCA found at curr
        return dist + distFromP[curr];
    }
};
