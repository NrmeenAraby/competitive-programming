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
const int MOD = 1e8;
string s;
const int N = 25;
ll dp[N][2][4];
ll solve(int idx=0,bool tight=1,int count=0) { 
    if (count > 3)
        return 0;
    if (idx == s.size())
        return 1;

    if (dp[idx][tight][count] != -1)
        return  dp[idx][tight][count];

    dp[idx][tight][count] = 0;
    int end = tight ? s[idx] - '0' : 9;
    for (int i = 0; i <= end; i++) {
        dp[idx][tight][count] += solve(idx + 1,tight&&(i==end), count + (i != 0));
    }
   
    return dp[idx][tight][count];
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        s = to_string(r);
        memset(dp, -1, sizeof dp);
        ll ans = solve();
        s = to_string(l - 1);
        memset(dp, -1, sizeof dp);
        ans -= solve();
        cout<<ans<<endl;
    }
    return 0;
}
