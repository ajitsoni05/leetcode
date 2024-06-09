class Solution {
public:
    vector<int> tokenizer(string version){
        istringstream iss(version);
        vector<int>tokens;
        string token;
         // Parsing using std::getline with a comma delimiter
        while (getline(iss, token, '.')) {
            tokens.push_back(stoi(token));
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<int>t1=tokenizer(version1);
        vector<int>t2=tokenizer(version2);
        if(t1.size()<t2.size()){
            t1.resize(t2.size(),0);
        }else if(t2.size()<t1.size()){
            t2.resize(t1.size(),0);
        }
        for(int i=0;i<t1.size();i++){
            if(t1[i]>t2[i])return 1;
            else if(t1[i]<t2[i])return -1;

        }
        return 0;
    }
};