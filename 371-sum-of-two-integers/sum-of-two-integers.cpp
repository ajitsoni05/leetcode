class Solution {
public:
    int getSum(int a, int b) {
    while (b != 0) {
        int carry = (unsigned int)(a & b) << 1; // calculate carry
        a = a ^ b; // calculate sum without carry
        b = carry; // set b to carry for next iteration
    }
    return a;
}
};