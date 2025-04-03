/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    static bool compare(pair<int, int> i1, pair<int, int> i2) {
        if (i1.first == i2.first)
            return i1.second < i2.second;
        else
            return i1.first < i2.first;
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

        /*
          Only 1 merge
          get the unique intervals of each employee
          form vector<Interval> with unique intervals
          then merge intervals
          return the gap
        */

        // create a set for unique intervals
        set<pair<int, int>> s;
        vector<pair<int, int>> intervals;
        for (int i = 0; i < schedule.size(); i++) {
            for (int j = 0; j < schedule[i].size(); j++) {
                s.insert({schedule[i][j].start, schedule[i][j].end});
            }
        }

        for (auto ele : s) {

            intervals.push_back(ele);
        }

        // sort intervals
        sort(intervals.begin(), intervals.end(), compare);

        int st = intervals[0].first;
        int end = intervals[0].second;

        int n = intervals.size();
        // merge intervals

        vector<Interval> intvs;
        for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= end) {  // Overlapping intervals
            end = max(end, intervals[i].second);
        } else {  // Non-overlapping interval, push current and reset
            intvs.push_back(Interval(st, end));
            st = intervals[i].first;
            end = intervals[i].second;
        }
    }
         Interval* il = new Interval();
         il->start = st;
         il->end = end;
        
        intvs.push_back(*il);

        vector<Interval>ans;

        st =intvs[0].end;
        end = intvs[1].start;

        for(int i=0;i<intvs.size();i++){
            cout<<intvs[i].start<<" "<<intvs[i].end<<endl;
        }

        st =intvs[0].end;
        end = intvs[1].start;

        for(int i=0;i<intvs.size();i++){
            Interval*intv = new Interval();
            intv->start = st;
            intv->end = end;
            ans.push_back(*intv);
            if(i < intvs.size()-1){
                st = intvs[i].end;
                end = intvs[i+1].start;
            }
        }

       ans.erase(ans.begin());




        return ans;
    }
};