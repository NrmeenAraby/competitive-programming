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
const int N = 59049; //3^10 possibilties
int n;
vector<string>v;
ll dp[105][N+5];
int pw3[10];     //stores value of each position : 3^0 =1, 3^1=3 ,3^2=9 .....
ll solve(int idx = 0, int mask_3_based=0) {

    if (idx == n)
        return 0;

    if (dp[idx][mask_3_based] != -1)
        return dp[idx][mask_3_based];

    dp[idx][mask_3_based] = 0;
    bool valid = true;
    int new_mask = mask_3_based;
    for (int i = 0; i < v[idx].size(); i++) {
        int digit = v[idx][i] - '0';
        int cnt = (new_mask / pw3[digit]) % 3; //think of it like decimal nums, if u have 48371 and u wanna the hundreds digit so u do: 48371 / 100 = 483 then 483 % 10 = 3
        if (cnt == 2) {
            valid = false;
            break;
        }
        new_mask+= pw3[digit]; //adding one for the cntr of that digit
    }
    if (valid) { // so u can try to take it and to leave it
        dp[idx][mask_3_based] = max(dp[idx][mask_3_based],solve(idx + 1, new_mask) + stoll(v[idx]));//take it
    }
    dp[idx][mask_3_based] = max(dp[idx][mask_3_based],solve(idx + 1, mask_3_based) );//leave it

    return dp[idx][mask_3_based];

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    pw3[0] = 1;
    for (int i = 1; i <= 9; i++) {
        pw3[i] = pw3[i - 1] * 3; 
    }
    while (t--) { 
        cin >> n;
        v.clear();
        v.resize(n);
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << solve()<<endl;
    }
    return 0;
} 
