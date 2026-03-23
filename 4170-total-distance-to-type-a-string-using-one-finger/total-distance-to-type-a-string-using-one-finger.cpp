class Solution {
public:
    int totalDistance(string s) {
        unordered_map<char,pair<int,int>>mp;
        mp['q'] = {0,0};
        mp['w'] = {0,1};
        mp['e'] = {0,2};
        mp['r'] = {0,3};
        mp['t'] = {0,4};
        mp['y'] = {0,5};
        mp['u'] = {0,6};
        mp['i'] = {0,7};
        mp['o'] = {0,8};
        mp['p'] = {0,9};
        mp['a'] = {1,0};
        mp['s'] = {1,1};
        mp['d'] = {1,2};
        mp['f'] = {1,3};
        mp['g'] = {1,4};
        mp['h'] = {1,5};
        mp['j'] = {1,6};
        mp['k'] = {1,7};
        mp['l'] = {1,8};
        mp['z'] = {2,0};
        mp['x'] = {2,1};
        mp['c'] = {2,2};
        mp['v'] = {2,3};
        mp['b'] = {2,4};
        mp['n'] = {2,5};
        mp['m'] = {2,6};

        int ans = abs(mp[s[0]].first - 1) + mp[s[0]].second - 0;
        for(int i = 1; i < s.size(); i++){
            ans += abs(mp[s[i]].first - mp[s[i-1]].first) + abs(mp[s[i]].second - mp[s[i-1]].second);
        }
        return ans;
    }
};