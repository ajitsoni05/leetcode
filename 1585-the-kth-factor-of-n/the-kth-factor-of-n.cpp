class Solution {
public:
    int kthFactor(int n, int k) {
        /*
            n k
        */

        // find factors till sqrt(n)

        int counter = 0;

        for(int i = 1; i <= n; i++){
            if(n%i == 0) {
                counter++;

                if(k == counter) return i;
            }
        }
        return -1;
    }
};