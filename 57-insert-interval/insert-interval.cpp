class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) { // insert and merge
        intervals.push_back(newInterval);
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>>merged;

        for(auto it:intervals){
            if(merged.empty()|| merged.back()[1]<it[0]){
                merged.push_back(it);
            }else{
                merged.back()[1]=max(merged.back()[1],it[1]);
            }
        }

        return merged;
    }
};