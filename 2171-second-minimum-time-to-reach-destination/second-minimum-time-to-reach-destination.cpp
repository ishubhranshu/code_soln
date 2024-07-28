class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> f(n + 1, INT_MAX), s(n + 1, INT_MAX);
        f[1] = 0;
        queue<pair<int, int>> q;
        q.push({1, 0});

        while (!q.empty()) {
            int cnode = q.front().first;
            int ctime = q.front().second;
            q.pop();

            for (int neigh : adj[cnode]) {
                int ntime = ctime + time;
                if ((ctime / change) % 2 == 1) {
                    ntime += change - (ctime % change);
                }

                if (ntime < f[neigh]) {
                    s[neigh] = f[neigh];
                    f[neigh] = ntime;
                    q.push({neigh, ntime});
                } else if (ntime > f[neigh] && ntime < s[neigh]) {
                    s[neigh] = ntime;
                    q.push({neigh, ntime});
                }
            }
            
            if (s[n] != INT_MAX) {
                return s[n];
            }
        }

        return -1;
    }
};
