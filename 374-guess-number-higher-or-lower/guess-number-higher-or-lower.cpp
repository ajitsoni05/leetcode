/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int pick=guess(n);
        if(pick==-1)return guessNumber(n-1);
        if(pick==1)return guessNumber(n+1);
        return n;
    }
};