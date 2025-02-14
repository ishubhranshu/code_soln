class ProductOfNumbers {
public:
    vector<int> cProd;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num==0)
        {
            cProd.clear();
            return;
        }
        int n=cProd.size();

        if(n==0)
            cProd.push_back(num);
        else
            cProd.push_back(num*cProd[n-1]);
    }
    
    int getProduct(int k) {
        int n=cProd.size();
        if(k>n)
            return 0;

        if(k==n)
            return cProd.back();
        
        return cProd[n-1]/cProd[n-1-k]; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */