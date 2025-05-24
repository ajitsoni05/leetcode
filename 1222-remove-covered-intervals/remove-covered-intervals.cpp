class Solution {
public:
    static bool comp(const vector<int>&A,const vector<int>&B){
        if(A[0]==B[0])return A[1]>B[1];
        return A[0]<B[0];
    }
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
        // sort the intervals
        sort(intervals.begin(),intervals.end(),comp);


        // merged
        vector<vector<int>>merged;
        merged.push_back(intervals[0]);

        // merge
        for(int i = 1; i<intervals.size();i++){
            if(merged.back()[1]>=intervals[i][1] and merged.back()[0]<=intervals[i][0]){
                continue;
            }else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       // first let's merge the intervals
       vector<vector<int>>merged =  mergeIntervals(intervals);
        return merged.size();
       
    
    }
};