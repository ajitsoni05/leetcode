class Solution {
public:
    int numDiff(string a, string b) {
        int n = a.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i])
                count++;
        }

        return count;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_map<string, int> stringToIndex;

        stringToIndex[beginWord] = 0;

        int n = wordList.size() + 1;
        int target = n;
        bool found = false;
        for (int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord){
                target = i + 1;
                found = true;
            }
            stringToIndex[wordList[i]] = i + 1;
        }

        if(!found)return 0;




        // adj
        vector<vector<int>> adj(n);


        for (int i = 0; i < wordList.size(); i++) {
            int num_diff = numDiff(beginWord, wordList[i]);
            if (num_diff == 1) {
                adj[0].push_back(i + 1);
                adj[i + 1].push_back(0);
            }
            for (int j = i + 1; j < wordList.size(); j++) {
                int num_diff = numDiff(wordList[i],wordList[j]);
                if(num_diff == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        queue<int> q;

        q.push(0);

        int dist = 0;
        set<int> vis;
        vis.insert(0);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                if (node == target)
                    return dist+1;

                for (auto nb : adj[node]) {
                    if (!vis.count(nb)){
                        vis.insert(nb);
                        q.push(nb);
                    }
                }
            }
            dist++;
        }

        return 0;
    }
};