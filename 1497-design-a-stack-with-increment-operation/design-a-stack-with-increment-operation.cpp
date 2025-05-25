class CustomStack {
public:
    stack<pair<int, int>> s;
    int maxS;
    int index;
    unordered_map<int, int> indexMap;
    CustomStack(int maxSize) : maxS(maxSize), index(-1) {}

    void push(int x) {
        if (s.size() < maxS)
            s.push({x, ++index});
    }

    int pop() {
        if (!s.empty()) {
            auto [val, idx] = s.top();
            s.pop();
            int temp = val + indexMap[idx];

            // propagate the increment down
            indexMap[idx - 1] += indexMap[idx];
            indexMap.erase(idx);

            index--;
            return temp;
        }
        return -1;
    }

    void increment(int k, int val) {
        if (k - 1 <= index)
            indexMap[k - 1] += val;
        else  indexMap[index] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */