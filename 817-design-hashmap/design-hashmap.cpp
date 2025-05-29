class TreeNodePair {
public:
    int val;
    int keyval;
    TreeNodePair* left;
    TreeNodePair* right;

    TreeNodePair(int value, int keyvalue)
        : val(value), keyval(keyvalue), left(nullptr), right(nullptr) {}
};
class MyHashMap {
public:
    TreeNodePair* deleteNode(TreeNodePair* root, int key) {
    if (!root) return nullptr;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left && !root->right) {
            return nullptr;
        } else if (!root->left || !root->right) {
            return root->left ? root->left : root->right;
        } else {
            TreeNodePair* successor = root->right;
            while (successor->left)
                successor = successor->left;

            root->val = successor->val;
            root->keyval = successor->keyval;
            root->right = deleteNode(root->right, successor->val);
        }
    }
    return root;
}

    TreeNodePair* searchBST(TreeNodePair* root, int val) {
        // iterative approach
        while (root and root->val != val) {
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
    TreeNodePair* insertIntoBST(TreeNodePair* root, int val, int keyvalue) {
        TreeNodePair* node = root;
        while (node) {
            if (node->val > val) {
                // insert into left subtree
                if (!node->left) {
                    node->left = new TreeNodePair(val, keyvalue);
                    return root;
                } else
                    node = node->left;
            } else if (node->val < val) {
                // insert into right subtree
                if (!node->right) {
                    node->right = new TreeNodePair(val, keyvalue);
                    return root;
                } else
                    node = node->right;
            }
        }
        return new TreeNodePair(
            val, keyvalue); // if it is not inserted during iteration
    }
    vector<TreeNodePair*> hashMap;
    int len = 100;
    MyHashMap() { hashMap.resize(100); }

    void put(int key, int value) {

        int bucket = key % 100;

        TreeNodePair* root = hashMap[bucket];

        TreeNodePair* keyNode = searchBST(root, key);

        if (keyNode)
            keyNode->keyval = value;
        else {
            TreeNodePair* modifiedRoot = insertIntoBST(root, key, value);
            hashMap[bucket] = modifiedRoot;
        }
    }

    int get(int key) {
        int bucket = key % 100;

        TreeNodePair* root = hashMap[bucket];

        TreeNodePair* keyNode = searchBST(root, key);

        if (keyNode)
            return keyNode->keyval;

        return -1;
    }

    void remove(int key) {
        int bucket = key % 100;

        TreeNodePair* root = hashMap[bucket];

        TreeNodePair* modifiedRoot = deleteNode(root, key);

        hashMap[bucket] = modifiedRoot;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */