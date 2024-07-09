class Solution {
public:
    bool isPerfectSquare(int num) {
        double sq=sqrt(num);
        return floor(sq)==ceil(sq);
    }
};