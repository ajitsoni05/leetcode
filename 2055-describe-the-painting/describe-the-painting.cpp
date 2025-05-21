class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        
        map<long long, long long> Map;

        for (auto& seg : segments) {
            Map[seg[0]] += seg[2];
            Map[seg[1]] -= seg[2];
        }

        vector<vector<long long>> ans;
        long long current = 0;

        for (auto& [pos, delta] : Map) {
            if (!ans.empty() && current != 0) {
                // Set the end of the last segment
                ans.back()[1] = pos;
            }

            current += delta;

            if (current != 0) {
                // Start a new interval with end = -1 as placeholder
                ans.push_back({pos, -1, current});
            }
        }

        // Remove the last segment if it still has end == -1
        if (!ans.empty() && ans.back()[1] == -1) {
            ans.pop_back();
        }

        return ans;
    }
};
