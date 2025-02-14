// 1352. Product of the Last K Numbers

class ProductOfNumbers {
    public:
        vector<int> arr;
        ProductOfNumbers() {
            
        }
        
        void add(int num) {
            arr.push_back(num);
        }
        
        int getProduct(int k) {
            int n = arr.size();
            int pro = 1;
            for(int i=n-1; i>=n-k; i--){
                pro *= arr[i];
            }
            return pro;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */