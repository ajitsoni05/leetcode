class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*
        
            5 - 000000101
            6 - 000000111
            7 - 000000111
            8 - 000001000
            9 - 000001001
        */
        int num = 0;
        for(int i=31;i>=0;i--){
            if(left>>i == right >>i){
            num = num | (left>>i)<<i;
            continue;
            }
            else{
                return num;
            }
        }
        return num;
    }
};