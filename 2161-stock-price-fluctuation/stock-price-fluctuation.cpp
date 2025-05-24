class StockPrice {
public:
    // each record has a timestamp and price of stock
    // another record appear later with same timestamp

    // this method uses lazy deletion

    // for price per ts we can use descending order map
    map<int,int,greater<int>>mp;

    // max heap
    priority_queue<pair<int,int>>maxHeap;

    // min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;


    StockPrice() {
      
    }
    
    void update(int timestamp, int price) {
        // update price at same timestamp

       mp[timestamp] = price;

       maxHeap.push({price,timestamp});
       minHeap.push({price,timestamp});

        
    }
    
    int current() {
        // price corresponding to the last timestamp
        return mp.begin()->second;
        
    }
    
    int maximum() {
        // max until now
        while(!maxHeap.empty()){
            pair<int,int>top = maxHeap.top();
            int price = top.first;
            int ts = top.second;

            if(mp[ts]!=price)maxHeap.pop();
            else{
                return price;
            }
        }
        return -1;

    }
    
    int minimum() {
        // min
        while(!minHeap.empty()){
            pair<int,int>top = minHeap.top();
            int price = top.first;
            int ts = top.second;

            if(mp[ts]!=price)minHeap.pop();
            else{
                return price;
            }
        }
        return -1;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */