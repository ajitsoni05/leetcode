class Solution {
public:
    int getDiff(string a, string b) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                count++;
        }
        return count;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene)
            return 0;

        unordered_map<string, int> stringToIndex;
        stringToIndex[startGene] = 0;
        int n = bank.size() + 1;

        if (find(bank.begin(), bank.end(), endGene) == bank.end())
            return -1;

        vector<vector<int>> adj(n + 2);
        for (int i = 0; i < bank.size(); i++) {
            stringToIndex[bank[i]] = i + 1;
        }

        bool inBank = false;
        if (stringToIndex.count(endGene))
            inBank = true;
        else
            stringToIndex[endGene] = n + 1;

        int target = stringToIndex[endGene];

        // Build the graph
        for (int i = 0; i < bank.size(); i++) {
            int node = stringToIndex[bank[i]];

            if (getDiff(startGene, bank[i]) == 1) {
                adj[0].push_back(node);
                adj[node].push_back(0);
            }

            if (!inBank && getDiff(endGene, bank[i]) == 1) {
                adj[n + 1].push_back(node);
                adj[node].push_back(n + 1);
            }

            for (int j = i + 1; j < bank.size(); j++) {
                if (getDiff(bank[i], bank[j]) == 1) {
                    int node2 = stringToIndex[bank[j]];
                    adj[node].push_back(node2);
                    adj[node2].push_back(node);
                }
            }
        }

        // BFS to find shortest path
        queue<int> q;
        set<int> visitedSet;
        q.push(0);
        visitedSet.insert(0);
        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();

                if (node == target)
                    return dist;

                for (int nb : adj[node]) {
                    if (!visitedSet.count(nb)) {
                        visitedSet.insert(nb);
                        q.push(nb);
                    }
                }
            }
            dist++;
        }

        return -1;
    }
};
