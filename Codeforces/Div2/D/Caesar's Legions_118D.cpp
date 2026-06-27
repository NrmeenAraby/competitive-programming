#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <array>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <functional>
#include <bitset>
#include <cstring>
#include <iomanip>
#include <list>
#define ll  long long
using namespace std;
const int MAX = 2e3 + 5;
const int MOD = 1e8;
int n1, n2, k1, k2;
int dp[105][105][15][15][3];
int solve(int idx1=0,int idx2=0,int sum1=0,int sum2=0,int last=0) { //last:  1>>footmen , 2>>horsemen
    if (sum1 > k1 || sum2 > k2) {
        return 0;
    }
    if (idx1 == n1 && idx2 == n2  ) {
         return 1; 
    }

    if (dp[idx1][idx2][sum1][sum2][last] != -1)
        return dp[idx1][idx2][sum1][sum2][last];

    dp[idx1][idx2][sum1][sum2][last] = 0;

    if (idx1 < n1) {
        if (last == 1) {
            dp[idx1][idx2][sum1][sum2][last] = (dp[idx1][idx2][sum1][sum2][last] % MOD + solve(idx1 + 1, idx2, sum1 + 1, sum2, 1) % MOD) % MOD;
        }
        else {
            dp[idx1][idx2][sum1][sum2][last] = (dp[idx1][idx2][sum1][sum2][last] % MOD + solve(idx1 + 1, idx2, 1, sum2, 1) % MOD) % MOD;
        }
    }
    if (idx2 < n2) {
        if (last == 2) {
            dp[idx1][idx2][sum1][sum2][last] = (dp[idx1][idx2][sum1][sum2][last] % MOD + solve(idx1, idx2 + 1, sum1, sum2 + 1, 2) % MOD) % MOD;
        }
        else {
            dp[idx1][idx2][sum1][sum2][last] = (dp[idx1][idx2][sum1][sum2][last] % MOD + solve(idx1, idx2 + 1, sum1, 1, 2) % MOD) % MOD;
        }
    }
    return dp[idx1][idx2][sum1][sum2][last];
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        cin >> n1>>n2>>k1>>k2;
        memset(dp, -1, sizeof dp);
        cout << solve() << endl;
    }
    return 0;
}
