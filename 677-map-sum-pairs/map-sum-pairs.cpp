class Tn{
    public:
    vector<Tn*>children;
    int val;
    Tn():val(0){
        children.resize(26,nullptr);
    }
    
};
class MapSum {
public:
    unordered_map<string,int>mp;
    Tn* t;
    MapSum() {
        t = new Tn();
    }
    
    void insert(string key, int val) {
        Tn* temp = t;
        int sub = 0;
        if(mp.count(key)){
            sub = mp[key];
        }
        mp[key] = val;
        for(int i = 0; i < key.size(); i++){
            char c = key[i] - 'a';
            if(!temp->children[c]){
                temp->children[c] = new Tn();
            }
            temp = temp->children[c];
            temp->val += (val-sub);
        }
    }
    
    int sum(string prefix) {
        Tn* temp = t;

        for(int i =0; i <prefix.size();i++){
            char c = prefix[i] - 'a';
            if(!temp->children[c])return 0;
            else{
                  temp = temp->children[c];
            }
        }
        return temp->val;
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */