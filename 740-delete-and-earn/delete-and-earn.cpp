class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        unordered_map<int,int>points;
        vector<int>maxPoints;

        int maxNum = 0;

        for(auto num:nums){
            points[num]+= num;
            maxNum = max(maxNum,num);
        }


        maxPoints.resize(maxNum+1,0);


        maxPoints[1] = points.count(1) ? points[1] : 0;

        for(int num = 2; num <= maxNum; num++){
            maxPoints[num] = max(maxPoints[num-1],points[num] + maxPoints[num-2]);
        }

        return maxPoints[maxNum];




    }
};