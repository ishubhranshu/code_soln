class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> degree;

        // Step 1: Build adjacency list and calculate degree balance
        for (auto& pair : pairs) {
            adj[pair[0]].push_back(pair[1]);
            degree[pair[0]]--; // Out-degree
            degree[pair[1]]++; // In-degree
        }

        // Step 2: Find starting node
        int start = pairs[0][0];
        for (auto& d : degree) {
            if (d.second < 0) { // Start node should have negative balance
                start = d.first;
                break;
            }
        }

        // Step 3: Hierholzer's Algorithm to find Eulerian path
        vector<vector<int>> result;
        stack<int> stack;
        stack.push(start);

        while (!stack.empty()) {
            int node = stack.top();
            if (!adj[node].empty()) {
                int next = adj[node].back();
                adj[node].pop_back(); // Remove edge
                stack.push(next);
            } else {
                stack.pop();
                if (!stack.empty()) {
                    result.push_back({stack.top(), node});
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
