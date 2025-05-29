class MyHashSet {
public:
    int len = 1000001;
    vector<int>hash;
    MyHashSet() {
        hash.resize(len,-1);
    }
    
    void add(int key) {
        hash[key] = 1;
    }
    
    void remove(int key) {
          hash[key] = -1;
    }
    
    bool contains(int key) {
        return  hash[key] == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */