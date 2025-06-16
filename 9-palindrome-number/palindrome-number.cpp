class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string temp = s;
        reverse(temp.begin(),temp.end());

        return s == temp;
    }
};