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
int n;
vector<int>a;
int dp[MAX][2];
int solve(int idx=0,int current=0) { //current:  0>>friendo  1>>me
    if (idx == n)
        return 0;
    
    if (dp[idx][current] != -1) 
        return dp[idx][current];
    
    dp[idx][current] = 1e9;

    if (current == 0 ) {
        dp[idx][current] = min(dp[idx][current], solve(idx + 1, 1) + a[idx]);
        if (idx + 1< n) {
            dp[idx][current] = min(dp[idx][current], solve(idx + 2, 1) + a[idx]+a[idx+1]);

        }
    }
    else if (current == 1) {
        dp[idx][current]= min(dp[idx][current], solve(idx + 1, 0) );  
        if (idx + 1 < n) {
            dp[idx][current]= min(dp[idx][current], solve(idx+2, 0));
        }
    }
    
    return  dp[idx][current];
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof dp);
        cout << solve()<<endl;
    }
    return 0;
}
