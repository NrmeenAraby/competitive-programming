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
vector<pair<int, int>>prime_factors;
void factorize(int n) {
    for (int i = 2; i * i <= n; i++) {
        int power = 0;
        while (n % i == 0) {
            power++;
            n /= i;
        }
        if (power) {
            prime_factors.push_back({ i,power });
        }
    }
    if (n != 1) {
        prime_factors.push_back({ n,1 });
    }
}

const ll N = (1ll << 22ll);
int n;
int compatibility[22][22];
ll dp[22][N];
ll solve(int man=0,int womenBitmask=0) {
    if (__builtin_popcount(womenBitmask) == n)
        return 1;

    if (dp[man][womenBitmask] != -1)
        return dp[man][womenBitmask];

    dp[man][womenBitmask] = 0;
    for (int woman = 0; woman < n; woman++) {
        if (!((womenBitmask >> woman) & 1)) {
            if (compatibility[man][woman]) {
                dp[man][womenBitmask] = add(dp[man][womenBitmask], solve(man + 1, womenBitmask | (1 << woman)));
            }
        }
    }
    return dp[man][womenBitmask];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        cin >> n ;
        memset(dp, -1, sizeof dp);   
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> compatibility[i][j];
           }
        }
        cout << solve() << endl;
    }
    return 0;
}
