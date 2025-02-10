class Solution {
public:
    bool hasUniqueDigits(string num){
        unordered_map<char,int>numMap;

        for(int i=0;i<num.size();i++){
            if(numMap.count(num[i])>0)return false;
            else numMap[num[i]]=1;
        }
        return true;
                
    }
    int numberCount(int a, int b) {
        int cnt=0;
        for(int i=a;i<=b;i++){
            string numString= to_string(i);
            if(!hasUniqueDigits(numString))continue;
            else cnt++;
        }
        return cnt;
    }
};