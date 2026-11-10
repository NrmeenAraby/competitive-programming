class Solution {
private: 
    static const int N = 1e5 + 5;
    int dp[N];
    int n;
    vector<int>costs;
    int solve(int idx = 0) {
        if (idx == n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        dp[idx] = 1e9+5;

        for (int j = idx + 1; j <= min(n, idx + 3); j++) {
            dp[idx] = min(dp[idx], solve(j) + costs[j - 1] + (j - idx)*(j-idx));

        }
        return dp[idx];
    }
public:


    int climbStairs(int n, vector<int>& costs) {
        this->n = n;
        this->costs = costs;
        memset(dp, -1, sizeof dp);
        return solve();
    }
};
