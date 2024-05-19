class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq; 
    int mini=1;
    SeatManager(int n) {
        // mini=1;
    }
    
    int reserve() {
        if(!pq.empty())
        {
            int ans=pq.top();
            pq.pop();
            return ans;
        }
        int ans=mini;
        mini++;
        return ans;
    }
    void unreserve(int seatNumber) {
        pq.push(seatNumber);   
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */