class ValidWordAbbr {
public:
    unordered_map<string,int>mp;
    ValidWordAbbr(vector<string>& dictionary) {
        set<string>st;
        for(int i=0;i<dictionary.size();i++){
            int prev=st.size();
            st.insert(dictionary[i]);
            if(st.size()==prev)continue;
            mp[dictionary[i]]++;
            if(dictionary[i].size()>2){
                string abr=dictionary[i][0]+to_string(int(dictionary[i].size()-2))+dictionary[i][dictionary[i].size()-1];
                mp[abr]++;
            }
        }
    }
    
    bool isUnique(string word) {
        if(word.size()>2){
            string abr = word[0]+to_string(word.size()-2)+word[word.size()-1];
            if(mp.count(word)==0&&mp.count(abr)==0)return true;
            else if(mp.count(word)>0&&mp[abr]==1)return true;
            else return false;
        }else{
            if(mp.count(word)==0)return true;
            else if(mp.count(word)>0&&mp[word]==1)return true;
            else return false;

        }
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */