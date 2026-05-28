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
int n, k;
vector<int>v(MAX);
int dp[MAX];
int solve(int currTime = 1) {
    if (currTime >= n)
        return 0;

    if (dp[currTime] != -1)
        return dp[currTime];

    dp[currTime] = 0;
    dp[currTime] = max(dp[currTime], solve(currTime + 1));//leave
    if (v[currTime] <= n) {   //this condition just because we intializd v with values that greater than the allowed n seconds and we iterate over time starting from 1 and some seconds may have no interval so it holds 1e9
        dp[currTime] = max(dp[currTime], solve(v[currTime]) + 1); //take
    }
    return dp[currTime];
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < MAX; i++) {
            v[i] = 1e9;
        }
        int a, b;
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            v[a] = min(v[a], b);  //min end for this start
        }
        memset(dp, -1, sizeof dp);
        cout<<solve()<<endl;
    }
    return 0;
}
