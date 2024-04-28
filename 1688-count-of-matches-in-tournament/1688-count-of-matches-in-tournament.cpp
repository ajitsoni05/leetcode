class Solution {
public:
    int numberOfMatches(int n) {
        int mat=0;
        int temp=n;
        while(temp>1){
           
            if(temp%2){
                mat+=((temp-1)/2);
                temp=((temp-1)/2)+1;
            }else {
                mat+=temp/2;
                temp/=2;
            }
        }
        return mat;
    }
};