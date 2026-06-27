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
const int MAX = 1e3 + 5;
const int MOD = 1e8;
int n, m;
int dp[MAX][MAX];
vector<int>a;
int solve(int column, int prevRow) {
    if (column == m)
        return 0;

    if (dp[column][prevRow] != -1)
        return dp[column][prevRow];

    dp[column][prevRow] = 1e9;
    if (prevRow > 0) {
        dp[column][prevRow] = min(dp[column][prevRow], solve(column + 1, prevRow - 1) + abs(a[column] - (prevRow - 1)));
    }
    dp[column][prevRow] = min(dp[column][prevRow], solve(column + 1, prevRow ) + abs(a[column] - prevRow ));
    if (prevRow < n - 1) {
        dp[column][prevRow] = min(dp[column][prevRow], solve(column + 1, prevRow + 1) + abs(a[column] - (prevRow + 1)));
    }

    return dp[column][prevRow];
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        cin >> n>>m;
        int x;
        a.resize(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m;j++) {
                cin >> x;
                if (x == 1) {
                    a[j] = i;
                }
            }
        }
        memset(dp, -1, sizeof dp);
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            ans = min(ans, abs(a[0] - i) + solve(1, i));
        }
        cout << ans << endl;
    }
    return 0;
}
