class Solution {
public:
    unordered_map<char, int> charMap;

    string customSortString(string order, string s) {
     sort(s.begin(),s.end(),[order](char a,char b){
        return order.find(a) < order.find(b);
     });

        return s;
    }
};