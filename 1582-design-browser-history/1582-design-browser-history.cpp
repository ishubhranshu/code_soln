class BrowserHistory {
public:
    stack<string> right,left;
    BrowserHistory(string homepage) {
        left.push(homepage);
    }
    
    void visit(string url) {
        while (!right.empty()) {
            right.pop();
        }
        left.push(url);
    }
    
    string back(int steps) {

        while(steps-- && left.size()>1)
        {
            right.push(left.top());
            left.pop();
        }

        return left.top();
    }
    
    string forward(int steps) {
        while(steps-- && right.size())
        {
            left.push(right.top());
            right.pop();
        }

        return left.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */