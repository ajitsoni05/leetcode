class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        else if(s.size() == 1)return 1;

        int n = s.size();

        vector<int>dp(n+1,0);

        int twoBack = 1;
        int oneBack = 1;

        for(int i = 1; i < n; i++){
            int current = 0;
            if(s[i] != '0')  current += oneBack;
            if(stoi(s.substr(i-1,2)) <= 26 and stoi(s.substr(i-1,2)) >= 10)current += twoBack;

            twoBack = oneBack;
            oneBack = current;
        }

        return oneBack;

    }
};