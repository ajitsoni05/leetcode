class ProductOfNumbers {
public:
    vector<int>elements;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        elements.push_back(num);
        
    }
    
    int getProduct(int k) {
        int product = 1;
        while(k > 0 and product != 0){
            product *= elements[elements.size()-k];
            k--;
        }
        return product;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */