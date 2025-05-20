class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // slope 1 ,2 = slope 2, 3

        double slope1,slope2;

        vector<int>pointA = points[0];
        vector<int>pointB = points[1];
        vector<int>pointC = points[2];
        
        if(pointA == pointB || pointB == pointC || pointC == pointA)return false;

        // x2 - x1
        if(pointB[0]-pointA[0] == 0){
            slope1 = INT_MAX;
        }else{
        slope1 = ((pointB[1]-pointA[1]+0.0)/(pointB[0]-pointA[0]));
        }

        if(pointC[0]-pointB[0] == 0){
            slope2 = INT_MAX;
        }else{
        slope2 = ((pointC[1]-pointB[1]+0.0)/(pointC[0]-pointB[0]));
        }

        return slope1 != slope2 ;
    }
};