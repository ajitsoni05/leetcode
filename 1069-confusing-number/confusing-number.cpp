class Solution {
public:
    bool confusingNumber(int n) {
        string numStr = to_string(n);   
        int len = numStr.size();

        unordered_map<string,string>validNums;
        validNums["0"]="0";
        validNums["1"]="1";
        validNums["6"]="9";
        validNums["9"]="6";
        validNums["8"]="8";

        string temp = "";
        for(int i = len-1;i>=0;i--){
            if(validNums.count(to_string(numStr[i]-'0'))){
                temp += validNums[to_string(numStr[i]-'0')];
            }else{
                return false;
            }
        }
        return temp !=  numStr;


    }
};