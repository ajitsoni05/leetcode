class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> events;

        // Mark the start and end of each interval
        for (auto& interval : intervals) {
            events[interval[0]]++;
            events[interval[1] + 1]--;  // +1 ensures non-overlapping behavior
        }

        int maxGroups = 0, curr = 0;
        for (auto& e : events) {
            curr += e.second;
            maxGroups = max(maxGroups, curr);
        }

        return maxGroups;
    }
};
