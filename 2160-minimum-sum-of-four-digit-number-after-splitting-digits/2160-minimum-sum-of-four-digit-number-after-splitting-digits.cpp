class Solution {
public:
    int minimumSum(int num) {
        string s;
        while(num!=0){
            s+=to_string(num%10);
            num/=10;
        }
        sort(s.begin(),s.end());
        
        stringstream str(s);
        int x=0;
        str>>x;
        int d=x%10;x/=10;
        int c=x%10;x/=10;
        int b=x%10;x/=10;
        int a=x%10;x/=10;
        
        int n1=a*10+d;
        int n2=b*10+c;
       
        return n1+n2;
    }
};