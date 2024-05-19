class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.size()==right.size())
        {
            if(left.size()==0 || num<right.top())
                left.push(num);
            else
            {
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        }
        else
        {
            if(left.top()<num)
                right.push(num);
            else
            {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
    }
    
    double findMedian() {
        double ans=0;
        if(left.size()==right.size())
        {
            double a=left.top(), b=right.top();
            ans=(a+b)/2;
        }
        else
            ans=left.top();

        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */