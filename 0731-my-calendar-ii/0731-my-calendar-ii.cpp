class MyCalendarTwo {
public:
    vector<pair<int, int>> boook ,dbook;
    MyCalendarTwo() {
    }
    bool check(int s1, int e1, int s2, int e2) {
        return max(s1, s2) < min(e1, e2);
    }
    pair<int, int> calculate(int s1, int e1, int s2, int e2) {
        return make_pair(max(s1, s2), min(e1, e2));
    }
    
    bool book(int start, int end) {
        for(auto region: dbook)
        {
            if(check(region.first, region.second, start, end))
                return 0;
        }

        for(auto region: boook)
        {
            if(check(region.first, region.second, start, end))
                dbook.push_back(calculate(region.first, region.second, start, end));
        }
        boook.push_back({start, end});
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */