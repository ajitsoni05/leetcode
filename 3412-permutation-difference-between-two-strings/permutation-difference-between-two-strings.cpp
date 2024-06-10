class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<pair<char,int>>s1;
        vector<pair<char,int>>t1;
        for(int i=0;i<s.size();i++){
            s1.push_back({s[i],i});
        }

        for(int i=0;i<t.size();i++){
            t1.push_back({t[i],i});
        }
        sort(s1.begin(),s1.end());
        sort(t1.begin(),t1.end());

        int ans=0;

        for(int i=0;i<s.size();i++){
            ans+=abs(s1[i].second-t1[i].second);
        }

        return ans;
    }
};