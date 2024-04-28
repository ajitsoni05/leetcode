class Solution {
public:
    int pivotInteger(int n) {
        int totsum=(n*(n+1))/2;
        int cur_s=0;
        for(int i=1;i<=n;i++){
            if(totsum-i==cur_s)return i;
            else{
                cur_s+=i;
                totsum-=i;
            }
        }
        return -1;
    }
};