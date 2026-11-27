class Solution {
private:
    int n;
    int dp[1005][1505][2];
    vector<int>freeItmesCnt;
    int solve(int idx, int budget, int bought, vector<vector<int>>& items){
        if (idx >= n)
            return 0;

        if (dp[idx][budget][bought] != -1)
            return dp[idx][budget][bought];

        dp[idx][budget][bought] = 0;
        dp[idx][budget][bought] = max(dp[idx][budget][bought], solve(idx + 1, budget, 0,items));
        int cost = items[idx][1];
        if (budget >= cost) {
            if (bought) {
                dp[idx][budget][bought] = max(dp[idx][budget][bought], solve(idx, budget - cost, 1,items) + 1);
            }
            else {
                dp[idx][budget][bought] = max(dp[idx][budget][bought], solve(idx, budget - cost,1,items) + 1 + freeItmesCnt[idx]);
            }
        }
        return dp[idx][budget][bought];
    }
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        this->n = items.size();
        memset(dp, -1, sizeof dp);
        freeItmesCnt.assign(n,0);
        for (int i = 0; i < n; i++) {
            int factori = items[i][0];
            for (int j = 0; j < n; j++) {
                if (j != i && items[j][0] % factori == 0) {
                    freeItmesCnt[i]++;
                }
            }
        }
        return solve(0, budget, 0,items);
    }
};
