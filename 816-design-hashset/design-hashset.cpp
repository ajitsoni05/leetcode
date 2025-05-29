class MyHashSet {
public:
    int len = 100;
    vector<vector<int>>hash;
    MyHashSet() {
        hash.resize(100);
    }
    
    void add(int key) {

        int bucket = key%100;

        // check if bucket contains it
        for(int i = 0; i < hash[bucket].size();i++){
            if(hash[bucket][i]==key)return;
        }
        hash[bucket].push_back(key);
        
    }
    
    void remove(int key) {
        int bucket = key%100;
        // check if bucket contains it
        for(int i = 0; i < hash[bucket].size();i++){
            if(hash[bucket][i]==key){hash[bucket][i] = -1;return;}
        }
    }
    
    bool contains(int key) {
        int bucket = key%100;
        // check if bucket contains it
        for(int i = 0; i < hash[bucket].size();i++){
            if(hash[bucket][i]==key){return true;}
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */