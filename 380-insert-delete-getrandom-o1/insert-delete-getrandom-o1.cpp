class RandomizedSet {
public:

        unordered_map<int,int> hashMap;
        vector<int> ele;

    RandomizedSet() {

        
    }
    
    bool insert(int val) {

        if(hashMap.count(val)) {
            return false;
        } else {
            hashMap[val] = 0;
            ele.push_back(val);
            hashMap[val]=ele.size()-1; // {1} -> 4
            return true;
        }
        
    }
    
    bool remove(int val) {

        if(hashMap.count(val) and ele.size() >= 1) {

            int idx = hashMap[val];
            int lastIdx = ele.size()-1;
            int element = ele[lastIdx];
            
            // swap current with last
            swap(ele[idx],ele[lastIdx]);
            
            // update in hashMap for lastIdx
            hashMap[element] = idx;
            
            // remove val from hashMap
            ele.pop_back();
            hashMap.erase(val);
            return true;
        }

        return false;
    }
    
    int getRandom() {
        int sz = ele.size();
        return ele[rand()%sz];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */