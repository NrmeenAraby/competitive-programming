class Solution {
public:
    int n;
    int dp[50];
    int solve(int idx=0) {
        if(idx>n)
            return 0;
        if (idx == n)
            return 1;
        if (dp[idx] != -1)
            return dp[idx];

        dp[idx] = 0;
        dp[idx] += solve(idx + 1);
        dp[idx] += solve(idx + 2);

        return dp[idx];
    }
    int climbStairs(int n) {
        this->n = n;
        memset(dp, -1,sizeof dp);
        return solve();
    }
};
