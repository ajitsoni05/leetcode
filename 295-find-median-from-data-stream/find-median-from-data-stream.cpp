class MedianFinder {
public:
    // maxHeap: stores the smaller half of the numbers
    priority_queue<int> maxH;
    // minHeap: stores the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> minH;

    MedianFinder() {
        // Do nothing
    }
    
    void addNum(int num) {
        // Step 1: Add number to maxHeap (inverted sign for max-heap simulation)
        maxH.push(num);
        
        // Step 2: Ensure all elements in maxHeap are less than those in minHeap
        if (!minH.empty() && maxH.top() > minH.top()) {
            int temp = maxH.top();
            maxH.pop();
            minH.push(temp);
        }
        
        // Step 3: Balance the heaps sizes
        if (maxH.size() > minH.size() + 1) {
            int temp = maxH.top();
            maxH.pop();
            minH.push(temp);
        } else if (minH.size() > maxH.size()) {
            int temp = minH.top();
            minH.pop();
            maxH.push(temp);
        }
    }
    
    double findMedian() {
        if (maxH.size() > minH.size()) {
            return maxH.top();
        } else {
            return (maxH.top() + minH.top()) / 2.0;
        }
    }
};
