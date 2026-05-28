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
const int MAX = 2e5+5;
int n;
vector<ll>r1(MAX),r2(MAX);
ll dp[MAX][2];
ll solve(int i,bool last) {
    if (i >= n)
        return 0;

    if (dp[i][last] != -1)
        return dp[i][last];

    dp[i][last] = 0;

    if (last) {
        dp[i][last] = max(dp[i][last], solve(i + 1, !last) + r1[i]); //take
    }
    if (!last) {
        dp[i][last] = max(dp[i][last], solve(i + 1, !last) + r2[i]); //take
    }
    dp[i][last] = max(dp[i][last], solve(i + 1, last));//leave

    return dp[i][last];
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

        for (int i = 0; i < n; i++) {
            cin >> r1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> r2[i];
        }
        memset(dp, -1, sizeof dp);
        cout<<max(solve(0,true),solve(0,false));   //try starting from r1 once and from r2 another time 
    }
    return 0;
}
