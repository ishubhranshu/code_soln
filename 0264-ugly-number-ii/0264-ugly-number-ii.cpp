class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> seen;
        vector<int> primes = {2, 3, 5};
        
        pq.push(1);
        seen.insert(1);
        
        long currentUgly = 1;
        for (int i = 1; i < n; ++i) {
            currentUgly = pq.top();
            pq.pop();
            for (int prime : primes) {
                long nextUgly = currentUgly * prime;
                if (seen.find(nextUgly) == seen.end()) {
                    pq.push(nextUgly);
                    seen.insert(nextUgly);
                }
            }
        }
        
        return pq.top();
    }
};