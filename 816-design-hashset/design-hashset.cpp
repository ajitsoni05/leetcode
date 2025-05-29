

class MyHashSet {
private:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root) {
            /*
                check three conditions

                root->val and key

            */

            if (root->val > key) {
                // recursively delete key from left subtree and assign left
                // subtree
                root->left = deleteNode(root->left, key);

            } else if (root->val < key) {
                // recursively delete key from right subtree and assign right
                // subtree
                root->right = deleteNode(root->right, key);

            } else if (root->val == key) {
                /*
                    check for three conditions

                    - if root is leaft
                    - if root has either left or right but not both
                    - if root has both
                */

                if (!root->left and !root->right) {
                    // simply return NULL since consider it as deleted
                    return nullptr;
                } else if (!root->left || !root->right) {
                    // simply copy the non-empty node to itself
                    root = root->left ? root->left : root->right;
                } else if (root->left and root->right) {
                    // check the successor of the root
                    TreeNode* successor = root->right;

                    while (successor->left)
                        successor = successor->left;

                    // now copy this value onto root and then recursively delete
                    // successor
                    root->val = successor->val;

                    root->right = deleteNode(root->right, successor->val);
                }
            }
        }

        return root;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        // iterative approach
        while (root and root->val != val) {
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        while (node) {
            if (node->val > val) {
                // insert into left subtree
                if (!node->left) {
                    node->left = new TreeNode(val);
                    return root;
                } else
                    node = node->left;
            } else if (node->val < val) {
                // insert into right subtree
                if (!node->right) {
                    node->right = new TreeNode(val);
                    return root;
                } else
                    node = node->right;
            }
        }
        return new TreeNode(val); // if it is not inserted during iteration
    }

public:
    int len = 769;
    vector<TreeNode*> hash;
    MyHashSet() { hash.resize(len); }

    void add(int key) {

        int bucket = key % len;

        TreeNode* root = hash[bucket];

        // check if the key exists in the BST
        TreeNode* node = searchBST(root, key);

        if (!node) {
            TreeNode* modified = insertIntoBST(root, key);
            hash[bucket] = modified;
        }
    }

    void remove(int key) {
        int bucket = key % len;

        TreeNode* root = hash[bucket];
        // check if bucket contains it
        TreeNode* node = searchBST(root, key);

        if (node) {
            TreeNode* modified = deleteNode(root, key);
            hash[bucket] = modified;
        }
    }

    bool contains(int key) {
        int bucket = key % len;

        TreeNode* root = hash[bucket];
        // check if bucket contains it
        TreeNode* node = searchBST(root, key);
        if (node)
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */