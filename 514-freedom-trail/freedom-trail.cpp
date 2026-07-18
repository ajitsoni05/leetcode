class Solution {
public:
    string ring, key;
    unordered_map<char, vector<int>> rIMap;
    int kLen, rLen;
    map<pair<int,int>, int> mem;

    int recurse(int kIdx, int currIdx) {

        if (kIdx == kLen)
            return 0;

        if (mem.count({kIdx, currIdx}))
            return mem[{kIdx, currIdx}];

        char c = key[kIdx];

        int ans = INT_MAX;

        for (int idx : rIMap[c]) {

            int diff = abs(currIdx - idx);
            int rotate = min(diff, rLen - diff);

            ans = min(ans,
                      rotate + 1 + recurse(kIdx + 1, idx));
        }

        return mem[{kIdx, currIdx}] = ans;
    }

    int findRotateSteps(string ring, string key) {

        this->ring = ring;
        this->key = key;

        rLen = ring.size();
        kLen = key.size();

        for (int i = 0; i < rLen; i++)
            rIMap[ring[i]].push_back(i);

        return recurse(0, 0);
    }
};