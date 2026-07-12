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
const int MAX = 3e5 + 5;
const int MOD = 1e9+7;

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll sub(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
int n;
vector<vector<int>> neighbours(7);
vector<int>a;
int dp[MAX][7];
int solve(int idx , int before) {
    if (idx == n)
        return 0;

    if (dp[idx][before] != -1)
        return dp[idx][before];

    dp[idx][before] = 1e9;

    for (int i = 0; i < 4; i++) {
        int tmp = neighbours[before][i];
        if ( tmp== a[idx]) {
            dp[idx][before] = min(dp[idx][before], solve(idx + 1, tmp));
        }
        else {
            dp[idx][before] = min(dp[idx][before], solve(idx + 1, tmp)+1);

        }
    }
    return dp[idx][before];
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= 6; i++) {
        if (i == 1 || i == 6) {
            neighbours[i] = { 2,3,4,5 };
        }
        else if (i == 2 || i == 5) {
            neighbours[i] = { 1,3,4,6 };
        }
        else {
            neighbours[i] = { 1,2,5,6 };
        }
    }
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];           
        }
        if (n == 1) {
            cout << 0 << endl;
        }
        else {
            //memset(dp, -1, sizeof dp);       // this causes TLE, as it is mentioned in the stament that sum of n over all test cases does not exceed 3*10^5          
            for (int i = 0; i <= n; i++) {
                for (int j = 1; j <= 6; j++) {
                    dp[i][j] = -1;
                }
            }

            int ans = 1e9;
            int last_used = -1;
            for (int i = 1; i <= 6; i++) {
                int ret = solve(1, i);
                if (ret< ans) {
                    ans = ret;
                    last_used = i;
                }
                if (i == a[0] && ret == ans) {
                    last_used = i;
                }
            }
            if (last_used != a[0]) {
                ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
