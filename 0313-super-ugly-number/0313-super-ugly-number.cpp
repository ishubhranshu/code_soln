class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> ugly(n);
        ugly[0] = 1;
        
        int k = primes.size();
        vector<int> indices(k, 0);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        for (int i = 0; i < k; i++) {
            pq.push({primes[i], i});
        }
        
        for (int i = 1; i < n; i++) {
            ugly[i] = pq.top().first;
            
            while (!pq.empty() && pq.top().first == ugly[i]) {
                int idx = pq.top().second;
                pq.pop();
                indices[idx]++;
                pq.push({(long long)primes[idx] * ugly[indices[idx]], idx});
            }
        }
        
        return ugly[n-1];
    }
};