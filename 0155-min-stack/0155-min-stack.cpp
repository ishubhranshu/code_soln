class MinStack {
    stack<long long> stk;
    long long min;
public:
    MinStack() {
        min=LONG_MAX;
    }
    
    void push(int val) {

        if(stk.empty())
        {
            min=val;
            stk.push(val);
        }
        else if(min<=val)
            stk.push(val);
        else
        {
            long long newVal=2LL*val-min;
            min=val;
            stk.push(newVal);
        }
    }
    void pop() {
        if(stk.top() >= min)
            stk.pop();
        else
        {
            long long prevMin=2LL*min-stk.top();
            min=prevMin;
            stk.pop();
        }   
    }
    
    int top() {
        if(stk.top() >= min)
            return stk.top();
        
        return min;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */