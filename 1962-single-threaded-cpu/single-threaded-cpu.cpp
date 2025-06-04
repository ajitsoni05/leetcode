class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
                return a[2] < b[2];
            }
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i); // append index
        }

        sort(tasks.begin(), tasks.end(), comp);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq; // {processingTime, index}

        long long timer = 0;
        int i = 0;
        vector<int> result;

        while (i < n || !pq.empty()) {
            if (pq.empty() && timer < tasks[i][0]) {
                timer = tasks[i][0]; // jump forward in time
            }

            while (i < n && tasks[i][0] <= timer) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            if (!pq.empty()) {
                auto curr = pq.top(); pq.pop();
                timer += curr[0];
                result.push_back(curr[1]);
            }
        }

        return result;
    }
};
