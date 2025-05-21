class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        
        map<long long, long long> Map;  // Changed to long long for large color sums

        for (auto& seg : segments) {
            Map[seg[0]] += seg[2]; // Start of segment: add color
            Map[seg[1]] -= seg[2]; // End of segment: subtract color
        }

        vector<vector<long long>> ans;
        long long current = 0;
        long long prev = -1;

        for (auto& ele : Map) {
            long long pos = ele.first;
            long long delta = ele.second;

            if (current != 0) {
                // Add interval only if there's a non-zero color
                ans.push_back({prev, pos, current});
            }

            current += delta;
            prev = pos;
        }

        return ans;
    }
};
