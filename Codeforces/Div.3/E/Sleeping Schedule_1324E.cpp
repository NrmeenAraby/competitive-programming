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
int n, h, l, r;
vector<int>a;
int dp[MAX][MAX];
int solve(int idx = 0, int accum = 0) {
    if (idx == n)
        return 0;

    if (dp[idx][accum] != -1)
        return dp[idx][accum];
    dp[idx][accum] = 0;

    if ((accum + a[idx]) % h >= l && (accum + a[idx]) % h <= r){
        dp[idx][accum] = max(dp[idx][accum], solve(idx + 1, (accum + a[idx]) % h) + 1);
    }
    else {
        dp[idx][accum] = max(dp[idx][accum], solve(idx + 1, (accum + a[idx]) % h));

    }
    if ((accum + a[idx]-1) % h >= l && (accum + a[idx]-1) % h <= r) {
        dp[idx][accum] = max(dp[idx][accum], solve(idx + 1, (accum + a[idx]-1) % h) + 1);
    }
    else {
        dp[idx][accum] = max(dp[idx][accum], solve(idx + 1, (accum + a[idx]-1) % h));
    }

    return dp[idx][accum];
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
  //  cin >> t;
    while (t--) {
        cin >> n>>h>>l>>r ;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof dp);
        cout<<solve()<<endl;
    }
    return 0;
}
