class Tn {
public:
    Tn* left;
    Tn* right;

    Tn() : left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Tn* t = new Tn();
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            Tn* temp = t;
            for (int l = 31; l >= 0; l--) {
                int dig = (num >> l) & 1;
                if (dig == 0) {
                    if (!temp->left)
                        temp->left = new Tn();
                    temp = temp->left;
                } else {
                    if (!temp->right)
                        temp->right = new Tn();
                    temp = temp->right;
                }
            }
        }
        int maxAns = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            Tn* temp = t;

            int tmp = 0;
            for (int l = 31; l >= 0; l--) {
                int dig = (num >> l) & 1;
                if (dig == 0) {
                    if (temp->right) {
                        tmp |= (1 << l);
                        temp = temp->right;

                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->left) {
                        tmp |= (1 << l);
                        temp = temp->left;
                    } else {
                        temp = temp->right;
                    }
                }
                maxAns = max(maxAns, tmp);
            }
        }
        return maxAns;
    }
};