class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a != b)return a.size() > b.size() ? a.size() : b.size();
        return -1;
    }
};