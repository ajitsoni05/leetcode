class Solution {
public:
    double dist(pair<int,int>p1,pair<int,int>p2){
        int dx = abs(p1.first -p2.first);
        int dy = abs(p1.second - p2.second);
        return (dx*dx + dy*dy);
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
        /*
        goal is to find the minimum area rectangle
        
        */


        // we can find the mid point , what after that?
        
        // lets insert the points into pointset
        set<pair<int,int>>pointSet;

        for(int i = 0; i < points.size(); i++){
            pointSet.insert({points[i][0],points[i][1]});
        }

        // 
        double minArea = INT_MAX;

        for(int i = 0; i < points.size()-2;i++){
            for(int j = i+1; j < points.size()-1;j++){
                for(int k = j+1; k < points.size();k++){
                    pair<int,int>p1 = {points[i][0],points[i][1]};
                    pair<int,int>p2 = {points[j][0],points[j][1]};
                    pair<int,int>p3 = {points[k][0],points[k][1]};
                    pair<int,int>p4 = {{p1.first+p2.first-p3.first},{p1.second+p2.second-p3.second}};           
                    bool isPerpendicular = false;

                    int dx1 = p1.first - p3.first;
                    int dy1 = p1.second - p3.second;

                    int dx2 = p2.first - p3.first;
                    int dy2 = p2.second - p3.second;

                    if(dx1*dx2 + dy1*dy2 == 0)isPerpendicular = true;

                    if(pointSet.count(p4) and isPerpendicular){
                        double area = sqrt(dist(p1,p3))* sqrt(dist(p1,p4)); 
                        minArea = fmin(minArea,area);
                    }
                }
            }
        }
        return minArea == INT_MAX?0:minArea;
    }
};