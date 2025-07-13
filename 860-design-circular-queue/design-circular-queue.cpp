class MyCircularQueue {
public:
    vector<int>queue;
    int count;
    int cap;
    int headIndex;
    MyCircularQueue(int k):count(0),cap(k) {
        queue.resize(k);
        headIndex = 0;
    }
    
    bool enQueue(int value) {
        if(count == cap)return false;
        int tailIndex = (headIndex + count)%cap;
        queue[tailIndex] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(count == 0)return false;
        headIndex = (headIndex+1)%cap;
        count--;
        return true;
    }
    
    int Front() {
        if(count == 0)return -1;
        return queue[headIndex];
    }
    
    int Rear() {
        if(count == 0)return -1;
        return queue[(headIndex + count - 1)%cap];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */