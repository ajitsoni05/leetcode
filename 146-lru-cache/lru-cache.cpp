class LRUCache {
    int cap;
    list<pair<int,int>>lruCache; // key value pair
    unordered_map<int,list<pair<int,int>>::iterator>iteratorMap; // key and its iterator
public:
    LRUCache(int capacity):cap(capacity) {
        
    }
    
    int get(int key) {
        // key is not present
        if(iteratorMap.find(key) == iteratorMap.end()) return -1;

        // key is present
        auto keyIterator = iteratorMap[key];

        // get the value
        int val = keyIterator->second;
        // erase iterator
        lruCache.erase(keyIterator);

        // insert back into lru
        lruCache.push_back({key,val});
        iteratorMap[key] = --lruCache.end();

        return val;
        
    }
    
    void put(int key, int value) {
        // if key is present
        if(iteratorMap.find(key) != iteratorMap.end()){
            // simply remove iterator
            auto it = iteratorMap[key];
            lruCache.erase(it);
        }else if(lruCache.size() == cap){
            // remove first
            // get key
            auto p = lruCache.front();
            int key = p.first;
            iteratorMap.erase(key);
            lruCache.pop_front();
        }

        lruCache.push_back({key,value});
        iteratorMap[key] = --lruCache.end();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */