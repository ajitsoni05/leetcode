class Solution {
public:
    unordered_map<char, int> charMap;

    string customSortString(string order, string s) {
        for (int i = 0; i < order.size(); i++) {
            charMap[order[i]] = i;
        }

        sort(s.begin(), s.end(), [&](char a, char b) {
            if (charMap.count(a) && charMap.count(b))
                return charMap[a] < charMap[b];
            else if (charMap.count(a))
                return true;
            else if (charMap.count(b))
                return false;
            return a < b;
        });

        return s;
    }
};