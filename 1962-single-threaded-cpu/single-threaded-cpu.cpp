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
        long long timer = INT_MAX;
        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i); // index
            timer = min((int)timer, tasks[i][0]);
        }

        sort(tasks.begin(), tasks.end(), comp);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq; // {processingTime, index, enqueueTime}

        int iter = 0;
        vector<int> order;

        while (iter < tasks.size() || !pq.empty()) {
            while (iter < tasks.size() && tasks[iter][0] <= timer) {
                pq.push({tasks[iter][1], tasks[iter][2], tasks[iter][0]});
                iter++;
            }

            if (!pq.empty()) {
                vector<int> nextJob = pq.top();
                pq.pop();
                order.push_back(nextJob[1]);
                timer += nextJob[0];
            } else if (iter < tasks.size()) {
                timer = tasks[iter][0];
            }
        }
        return order;
    }
};
