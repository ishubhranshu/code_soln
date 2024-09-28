class MyCircularDeque {
public:
    vector<int> dq;
    int n;
    int count=0;
    int left=0, right;
    MyCircularDeque(int k) {
        dq.resize(k);
        n=k;
        right=k-1;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return 0;
        left=(left-1+n)%n;
        dq[left]=value;
        count++;
        return 1;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return 0;
        right=(right+1)%n;
        dq[right]=value;
        count++;
        return 1;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return 0;
        left=(left+1)%n;
        count--;
        return 1;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return 0;
        right=(right-1+n)%n;
        count--;
        return 1;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return dq[left];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        return dq[right];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */