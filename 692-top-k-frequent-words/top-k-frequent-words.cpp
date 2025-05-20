class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {
            freqMap[words[i]]++;
        }

        map<int, set<string>, greater<int>> rmp;

        for (auto it : freqMap) {
            rmp[it.second].insert(it.first);
        }

        for (auto ele : rmp) {
            for (auto it : ele.second) {
                ans.push_back(it);
                k--;
                if (k == 0)
                    break;
            }
            if (k == 0)
                break;
        }
        return ans;
    }
};