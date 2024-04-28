class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int num) {
        int x=num;
        int s_d=0;
        while(x!=0){
            s_d+=(x%10);
            x/=10;
        }
        
        if(num%s_d==0)return s_d;
        else return -1;
        
    }
};