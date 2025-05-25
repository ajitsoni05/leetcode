class FrontMiddleBackQueue {
public:
    deque<int> dq;

    FrontMiddleBackQueue() {
    }

    void pushFront(int val) {
        dq.push_front(val); // O(1)
    }

    void pushMiddle(int val) {
        int mid = dq.size() / 2;
        dq.insert(dq.begin() + mid, val); // O(n) in worst case
    }

    void pushBack(int val) {
        dq.push_back(val); // O(1)
    }

    int popFront() {
        if (dq.empty()) return -1;
        int val = dq.front();
        dq.pop_front(); // O(1)
        return val;
    }

    int popMiddle() {
        if (dq.empty()) return -1;
        int mid = (dq.size() - 1) / 2;  // for even size, take the "first" middle
        int val = dq[mid];
        dq.erase(dq.begin() + mid); // O(n) in worst case
        return val;
    }

    int popBack() {
        if (dq.empty()) return -1;
        int val = dq.back();
        dq.pop_back(); // O(1)
        return val;
    }
};
