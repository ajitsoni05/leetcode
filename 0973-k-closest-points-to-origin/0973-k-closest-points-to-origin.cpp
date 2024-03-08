class Solution {
public:
    
    static bool compare(pair<int,int>&a,pair<int,int>&b){
        double dist1=((a.first)*(a.first)+(a.second)*(a.second));
        double dist2=((b.first)*(b.first)+(b.second)*(b.second));
        
        return dist1<dist2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<pair<int,int>>coordinates;
        vector<vector<int>>ans;
        
        for(int i=0;i<points.size();i++)coordinates.push_back(make_pair(points[i][0],points[i][1]));
        sort(coordinates.begin(),coordinates.end(),compare);
        
        for(int i=0;i<k;i++){
            ans.push_back({coordinates[i].first,coordinates[i].second});
        }
        return ans;
    }
};