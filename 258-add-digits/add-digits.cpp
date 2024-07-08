class Solution {
public:
    int addDigits(int num) {
        if(num<=9) return num;
        
        int sum=0;
        string s=to_string(num);

        for(int i=0;i<s.size();i++)sum+=(s[i]-'0');

        return addDigits(sum);
    }
};