class RecentCounter {
public:
    multiset<int> mst;

    RecentCounter() {}

    int ping(int t) {
        mst.insert(t);
        int lower = t - 3000;

        // Count elements in [lower, t]
        auto l = mst.lower_bound(lower);
        auto r = mst.upper_bound(t);  // strictly greater than t

        return distance(l, r);
    }
};
