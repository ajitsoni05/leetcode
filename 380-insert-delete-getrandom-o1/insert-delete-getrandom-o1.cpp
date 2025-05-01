class RandomizedSet {
public:
    unordered_map<int,int> keymp; // val , index in the vector
    vector<int> keys;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(keymp.count(val)>0){
            return false;
        }else{
            int idx = keys.size();
            keymp[val]=idx;
            keys.push_back(val);
            return true;
        }
        
    }
    
    bool remove(int val) {
         if(keymp.count(val)>0){
            int idx = keymp[val];
            swap(keys.back(),keys[idx]);
            keys.pop_back();
            keymp[keys[idx]]=idx;
            keymp.erase(val);

            return true;
            
        }else{
            return false;
           
        }
    }
    
    int getRandom() {
        if(keys.size()>0){
        int idx = rand()%keys.size();
        return keys[idx];}
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */