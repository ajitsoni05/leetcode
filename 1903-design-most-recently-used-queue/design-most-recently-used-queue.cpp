class MRUQueue {
public:
    list<int>l;

    MRUQueue(int n) {
        for(int i = 0; i < n; i++){
            l.push_back(i+1);
        }
        
    }
    
    int fetch(int k) {
        auto it = l.begin();
        advance(it,k-1);
        int val = *it;
        l.erase(it);
        l.push_back(val);
        return val;
        
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */