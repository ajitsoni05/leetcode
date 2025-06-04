class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // by diagonal
        set<pair<int,int>>pointSet;

        for(int i = 0; i < points.size();i++){
            pointSet.insert({points[i][0],points[i][1]});
        }
        int ans = INT_MAX;

        for(int i = 0; i < points.size();i++){
            for(int j = i+1; j < points.size();j++){
                vector<int>p1 = points[i];
                vector<int>p2 = points[j];
                if(p1[0]==p2[0]||p1[1]==p2[1])continue;

                pair<int,int>p3 = {p1[0],p2[1]};
                pair<int,int>p4 = {p2[0],p1[1]};

                if(pointSet.count(p3) and pointSet.count(p4)){
                    ans = min(ans, abs(p3.first - p4.first)* abs(p3.second - p4.second));
                }
            }
        }
        return ans == INT_MAX? 0:ans;
    }
};