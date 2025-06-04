class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>allowedSet;
        allowedSet.insert(allowed.begin(),allowed.end());
        int size = allowedSet.size();

        int count = 0;

        for(int i = 0; i < words.size();i++){
            set<char>temp = allowedSet;
            bool inconsistent = false;
            for(int j = 0; j < words[i].size();j++){
                temp.insert(words[i][j]);
                if(temp.size() != size){
                    inconsistent = true;
                    break;
                }
            }
            if(!inconsistent)count++;
        }
        return count;
    }
};