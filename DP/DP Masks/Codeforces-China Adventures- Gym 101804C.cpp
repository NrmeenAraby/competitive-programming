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
//__popcnt(mask)
int n,a;
int diff_with_white[19];
int diff_with_each_other[19][19];
const ll N = (ll) 1 << (ll) 19;
int dp[19][N];
int solve(int last,int mask){ //last: means last qr code used
    if (__builtin_popcount(mask) == n)
        return 0;

    if (dp[last][mask] != -1)
        return dp[last][mask];

    dp[last][mask] = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            dp[last][mask] = min(dp[last][mask], solve(i, mask | (1 << i))+diff_with_white[i]+a);
            dp[last][mask] = min(dp[last][mask], solve(i, mask | (1 << i))+diff_with_each_other[last][i]);
        }
    }

    return dp[last][mask];
}
void build(int last, int mask) {
    cout << last + 1 << endl;
    if (__builtin_popcount(mask) == n)
        return ;

    int ans = solve(last, mask);
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int op1 = solve(i, mask | (1 << i)) + diff_with_white[i] + a;
            int op2 = solve(i, mask | (1 << i)) + diff_with_each_other[last][i];
            if (op1 == ans) {
                cout << '*' << endl;
                build(i, mask | (1 << i));
                return;
            }
            else if (op2 == ans) {
                build(i, mask | (1 << i));
                return;
            }
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        cin >> n >> a;
        int arr[18][21][21];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 21; j++) {
                //for (int k = 0; k < 21; k++) {
                //    int x;
                //    cin >> x;
                string s;
                cin >> s;
                for (int k = 0; k < s.size(); k++) {
                    arr[i][j][k] = s[k]-'0';
                    if (arr[i][j][k])
                        diff_with_white[i]++;
                }
                //}
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 21; k++) {
                    for (int l = 0; l < 21; l++) {

                        if(arr[i][k][l]!=arr[j][k][l])
                            diff_with_each_other[i][j]++;
                    }
                }
            }
        }


        memset(dp, -1, sizeof dp);
        int mn = INT_MAX;
        int st = 0;

        for (int i = 0; i < n; i++) {
            int ret = solve(i, (1 << i))+diff_with_white[i];
            if (ret<mn) {
                mn = ret;
                st = i;
            }
        }
        cout << mn << endl;
        build(st, (1 << st));
    }
    return 0;
} 
