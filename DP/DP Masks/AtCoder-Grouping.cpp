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
const int MAX = 2e5 + 5;
const int MOD = 1e9+7;

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll sub(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

//__builtin_popcount(mask)
int n;
const ll N = (1ll << 17ll);
int compatibility[16][16];
ll cost[N + 5];
ll dp[N+5];
ll solve(int mask=(1<<n)-1) { //(1<<n) -1 puts all the bits with 1
    if (mask == 0)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    dp[mask] = 0;
    for (int sub_mask = mask; sub_mask; sub_mask = (sub_mask - 1) & mask) {  // to get the submasks of mask
        dp[mask] = max(dp[mask], solve(mask^sub_mask) + cost[sub_mask]);  //mask ^ submask excludes the group rabbits from the mask
    }
    return dp[mask];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    //cin >> t;
    while (t--) { 
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> compatibility[i][j];
            }
        }

        for (int mask = 0; mask < (1 << n); mask++) { //so if u have a mask like this : 1011, u sum up a0,1 + a0,3 + a1,3
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if ((mask & (1 << i)) && (mask & (1 << j))) {
                        cost[mask] += compatibility[i][j];
                    }
                }
            }
        }

        memset(dp, -1, sizeof dp);
        cout << solve() << endl;
    }
    return 0;
} 
