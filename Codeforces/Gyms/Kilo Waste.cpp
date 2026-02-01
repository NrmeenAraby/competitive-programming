#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <numeric>
#include<queue>
#include<array>
#include<string>
#include <functional>
using namespace std;
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;

#define ll  long long
int n;
vector<int>dp(60000, MAX);
int p;
vector<int>r;
int solve(int rem) {
    if (rem <= 0)
        return rem * -1;  //waste

    if (dp[rem] != MAX)
        return dp[rem];

    for (int i = 0; i < p; i++) {
        dp[rem] = min(dp[rem], solve(rem - r[i]));
    }
    return dp[rem];
}
int main() {

    int k;
    cin >> k >> p;
    r.resize(p);
    for (int i = 0; i < p; i++) {
        cin >> r[i];
    }
    vector<int>need(k);
    for (int i = 0; i < k; i++) {
        cin >> need[i];
    }
    for (int i = 0; i < k; i++) {
        cout << solve(need[i])<<"\n";
    }
    return 0;
}
