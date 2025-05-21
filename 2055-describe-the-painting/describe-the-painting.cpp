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
        long long prev = -1;

        for (auto& [pos, delta] : Map) {
            if (current != 0) {
                ans.push_back({prev, pos, current});
            }
            current += delta;
            prev = pos;
        }

        return ans;
    }
};
