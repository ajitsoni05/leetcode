class Solution {
public:
    vector<string> partitionString(string s) {
        int left = 0;
        int right = 0;

        string temp="";

        set<string>seen;

        vector<string>ans;

        while(right < s.size()){
            temp += s[right++];

            if(!seen.count(temp)){
                seen.insert(temp);
                ans.push_back(temp);
                left = right;
                temp = "";
            }else{
                // do nothing

            }
        }
        return ans;
    }
};