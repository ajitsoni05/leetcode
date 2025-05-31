class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trustScore(n+1,0);

        for(int i = 0; i <trust.size();i++){
            int to = trust[i][1];
            int from = trust[i][0];

            trustScore[to]++;
            trustScore[from]--;
        }


        for(int i =1; i <=n;i++){
            if(trustScore[i]==n-1)return i;
        }

        // can be done using single array also
        return -1;
    }
};