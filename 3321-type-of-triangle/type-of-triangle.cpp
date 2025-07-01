class Solution {
public:
    bool isValid(int a,int b,int c){
        if((a+b > c) and (b+c > a) and (a+c > b))return true;
        return false;
    }
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if(isValid(a,b,c)){
            if(a == b and b == c)return "equilateral";
            else if(a == b || b == c || c == a)return "isosceles";
            else return "scalene";
        }

        return "none";

    }
};