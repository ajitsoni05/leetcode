class Solution {
public:
    int differenceOfSums(int n, int m) {
        int tots=(n*(n+1))/2;
        int divs=0;
        for(int i=1;i<=n;i++){
            if(i%m==0)divs+=i;
        }
        return tots-2*divs;
    }
};