class Tn{
    public:
    vector<Tn*>children;
    bool isTerm;
    Tn():isTerm(false){
        children.resize(26,NULL);
    }
};
class Trie {
public:
    Tn* t;
    Trie() {
        t =  new Tn();
    }
    
    void insert(string word) {
        Tn* temp = t;
        for(int i = 0; i < word.size(); i++){
            if(!temp->children[word[i]-'a']){
                temp->children[word[i]-'a'] = new Tn();
            }
            temp = temp->children[word[i]-'a'];
        }
        temp->isTerm = true;
    }
    
    bool search(string word) {
        Tn* temp = t;
        for(int i = 0;i<word.size();i++ ){
            if(!temp->children[word[i]-'a'])return false;
            else{
                temp = temp->children[word[i]-'a'];
            }
        }
        return temp->isTerm;
        
    }
    
    bool startsWith(string prefix) {
         Tn* temp = t;
        for(int i = 0;i<prefix.size();i++ ){
            if(!temp->children[prefix[i]-'a'])return false;
            else{
                temp = temp->children[prefix[i]-'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */