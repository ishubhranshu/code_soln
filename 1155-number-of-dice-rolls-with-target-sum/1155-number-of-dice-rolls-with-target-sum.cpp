class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int n, int k, int target) {
        if (n == 0) {
            return target == 0 ? 1 : 0;
        }

        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            if (target - i >= 0) {
                ans = (ans + solve(n - 1, k, target - i)) % mod;
            }
        }

        return dp[n][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        if (target < n || target > n * k) return 0;

        dp.resize(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target);
    }
};
