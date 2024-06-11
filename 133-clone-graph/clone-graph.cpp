class Solution {
public:
    void dfs(Node* node, unordered_map<Node*, Node*>& nmap) {
        nmap[node] = new Node(node->val);

        for (auto nb : node->neighbors) {
            if (!nmap.count(nb)) {
                dfs(nb, nmap);
            }
            nmap[node]->neighbors.push_back(nmap[nb]);
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        unordered_map<Node*, Node*> nmap;
        dfs(node, nmap);
        return nmap[node];
    }
};
