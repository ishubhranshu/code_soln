class CustomStack {
public:
    vector<int> stk;
    int top;
    int n;
    CustomStack(int maxSize) {
        stk.resize(maxSize);
        top=-1;
        n=maxSize-1;
    }
    
    void push(int x) {
        if(top==n)
            return;
        stk[++top]=x;
    }
    
    int pop() {
        if(top==-1)
            return -1;
        return stk[top--];
    }
    
    void increment(int k, int val) {
        for(int  i=0; i<=min(top, k-1); i++)
            stk[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */