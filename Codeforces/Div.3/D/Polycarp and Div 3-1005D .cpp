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
//__builtin_popcount(mask)
string s;
int dp[MAX][5];
int solve(int idx=0,int sum=0) { //sum: sum of digits mod 3
    if (idx == s.size())
        return 0;

    if (dp[idx][sum] != -1)
        return  dp[idx][sum];

    dp[idx][sum] = 0;
    if ((sum + (s[idx] - '0')) % 3 == 0) {
        dp[idx][sum] = max(dp[idx][sum], solve(idx + 1, 0) + 1); // cut
        //dp[idx][sum] = max(dp[idx][sum], solve(idx + 1, 0));  when sum%3 =0, it is always better to cut and adding another digit wont be a better choice 
    }
    else {
        dp[idx][sum] = max(dp[idx][sum], solve(idx + 1,0)); // cut, so start the next with sum = 0
        dp[idx][sum] = max(dp[idx][sum], solve(idx + 1, (sum + (s[idx] - '0')) % 3));

    }
    return dp[idx][sum];
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        cin >> s;
        memset(dp, -1, sizeof dp);   
        cout << solve() << endl;
    }
    return 0;
}
