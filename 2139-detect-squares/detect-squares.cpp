class DetectSquares {
public:
    map<pair<int,int>, int> mp;

    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int ans = 0;

        for (auto& [p2, cnt2] : mp) {
            int x2 = p2.first, y2 = p2.second;

            if (x1 == x2 || y1 == y2) continue; // must form diagonal
            if (abs(x1 - x2) != abs(y1 - y2)) continue; // must form square

            pair<int,int> p3 = {x1, y2};
            pair<int,int> p4 = {x2, y1};

            ans += cnt2 * mp[p3] * mp[p4];
        }

        return ans;
    }
};
