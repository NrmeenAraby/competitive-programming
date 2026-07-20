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
#include <intrin.h>
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

const ll N = (1ll << 19ll);
int n, m;
vector<int>a;
int satisGrid[20][20];
ll dp[20][N];
ll solve(int last,int bitmask) {
    if (__popcnt(bitmask) == m) //cant eat anymore
        return 0; 


    if (dp[last][bitmask] != -1)
        return dp[last][bitmask];

    dp[last][bitmask] = 0;
    for (int i = 0; i < n; i++) {
        if (!((bitmask >> i) & 1)) 
        {
            dp[last][bitmask] = max(dp[last][bitmask], solve(i, bitmask | (1 << i) ) + a[i] + satisGrid[last][i]);
        }
    }
    return dp[last][bitmask];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        int k;
        cin >> n >> m >> k;
        a.resize(n);
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int zis, zat,c;
        for (int i = 0; i < k; i++) {
            cin >> zis >> zat >> c;
            satisGrid[--zis][--zat] = c;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 1<<i)+a[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
