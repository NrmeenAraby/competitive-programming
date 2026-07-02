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
string s;
const int N = 2000+5;
int m, d;
ll dp[N][2][N];
ll solve(int idx=0,bool tight=1,int sum=0) { 
    if (idx == s.size())
        return (sum == 0); 

    if (dp[idx][tight][sum] != -1)
        return dp[idx][tight][sum];

    dp[idx][tight][sum] = 0;
    int end = tight ? s[idx] - '0' : 9;
    if (idx % 2) {
        if (d > end)
            return 0;
        dp[idx][tight][sum] = add(dp[idx][tight][sum], solve(idx + 1, tight && (d == end), (sum * 10 + d) % m));
    }
    else {
        for (int i = 0; i <= end; i++) {
            if (i != d) {
                dp[idx][tight][sum] = add(dp[idx][tight][sum], solve(idx + 1, tight && (i == end), (sum * 10 + i) % m));
            }
        }
    }
    return dp[idx][tight][sum];
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    //cin >> t;
    while (t--) {
       
        cin >> m >> d;
        string a, b;
        cin >> a >> b;
        s = b;
        memset(dp, -1, sizeof dp);
        ll ans = solve();
        s = a;
        memset(dp, -1, sizeof dp);
        ans = sub(ans, solve());
        int sum = 0,flag=1;
        for (int i = 0; i < a.size(); i++) { //as we cant say s=a-1 before the second solve call (we cant do math operations directly as the numbers are huge)
            if (i % 2) {
                if (a[i]-'0' != d) {
                    flag = 0;
                    break;
                }

            }
            else {
                if (a[i]-'0' == d) {
                    flag = 0;
                    break;
                }
            }
            sum = (sum * 10 + a[i] - '0') % m;
        }
        
        if (flag && sum==0) {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
