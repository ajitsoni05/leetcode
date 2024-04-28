class Solution {
public:
    int countDigits(int num) {
        int cnt=0;
        int temp=num;
        while(temp!=0){
            int dig=temp%10;
            temp/=10;
            if(dig!=0&&num%dig==0)cnt++;
        }
        return cnt;
    }
};