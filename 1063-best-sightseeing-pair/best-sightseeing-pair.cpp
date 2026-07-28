class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        /*
            we can fix a right and use it as values[r] - r
            and for that right we can have lefts and add it to right as values[l] + l
            we can have a running max left 
        */

        int n = values.size();
        vector<int>maxLeft(n,0);
        

        // maxLeft at 0 is same 
        maxLeft[0] = values[0] - 0;

        // store max score
        int maxScore = 0;
        
        for(int i = 1; i < n; i++){
            int currentRightScore = values[i] - i;
            maxScore = max(maxScore, maxLeft[i - 1] + currentRightScore);

            // update maxLeft for i
            maxLeft[i] = max(maxLeft[i - 1], values[i] + i);

        }
        return maxScore;

    }
};