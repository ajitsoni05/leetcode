class StockPrice {
    unordered_map<int, int> timestampPrice;
    map<int, int> priceCount; // price -> frequency
    int latestTimestamp = 0;

public:
    void update(int timestamp, int price) {
        if (timestampPrice.count(timestamp)) {
            int oldPrice = timestampPrice[timestamp];
            if (--priceCount[oldPrice] == 0) {
                priceCount.erase(oldPrice);
            }
        }
        timestampPrice[timestamp] = price;
        priceCount[price]++;
        latestTimestamp = max(latestTimestamp, timestamp);
    }

    int current() {
        return timestampPrice[latestTimestamp];
    }

    int maximum() {
        return priceCount.rbegin()->first;
    }

    int minimum() {
        return priceCount.begin()->first;
    }
};
