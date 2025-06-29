class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string,string>stringVal;
        int n = replacements.size();

        for(int i = 0; i < n; i++) {
            stringVal[replacements[i][0]] = replacements[i][1];
        }
        
        vector<string>ans;

        stringstream ss(text);

        string temp = "";

        while(getline(ss,temp,'%')){
            if(stringVal.count(temp)){
                string smallAns = applySubstitutions(replacements,stringVal[temp]);
                ans.push_back(smallAns);
            }else if(temp != ""){
                ans.push_back(temp);
            }
        }

        string finalAns = "";
        for(int i = 0; i < ans.size();i++){
            finalAns+= ans[i];
        }

        return finalAns;
    }
};