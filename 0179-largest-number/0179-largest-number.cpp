#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool comp(int a, int b) {
        string n1 = to_string(a);
        string n2 = to_string(b);
        return (n1 + n2) > (n2 + n1);
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string ans;
        for (int i = 0; i < nums.size(); i++) {
            ans += to_string(nums[i]);
        }
        // Handling leading zeros
        if (ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};
