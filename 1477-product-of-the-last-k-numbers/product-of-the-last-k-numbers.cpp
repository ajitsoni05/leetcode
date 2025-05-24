class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    int size = 0;
    ProductOfNumbers() { prefixProduct.push_back(1); }

    void add(int num) {
        if (num == 0) {
            prefixProduct = {1};
            size = 0;
            return;
        }
        prefixProduct.push_back(prefixProduct.back() * num);
        size++;
    }

    int getProduct(int k) {
        if (size < k)
            return 0;
        else {
            return prefixProduct[size] / prefixProduct[size-k];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */