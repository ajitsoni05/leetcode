class Solution {
public:
    vector<vector<int>>memo;
    int n;
    int numDays;
    vector<int>jobs;
    int dp(int idx,int d){
        if(idx == n and d == numDays){ // either of the two have finished
            return 0;
        }else if(idx == n || d == numDays)return INT_MAX; // not finished
    
        if(memo[idx][d]!= -1)return memo[idx][d];

        int curMax = 0;
        int res = INT_MAX;

        for(int i = idx; i < n; ++i){
            curMax = max(curMax,jobs[i]);
            int smallAns = dp(i+1,d+1);
            if(smallAns != INT_MAX){
                res = min(res,curMax+smallAns);
            }
        }
        return memo[idx][d] = res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // states - idx, numDays
        n = jobDifficulty.size();
        numDays = d;
        memo.assign(n,vector<int>(d,-1));
        if(n < d)return -1;
        jobs = jobDifficulty;
        return dp(0,0);
        
    }
};