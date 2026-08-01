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
const int N = 500;
int sum;
string prevNum,s;
int dp[N][305][2];
bool solve(int idx = 0, int curr = 0, bool greater = false) {
    if (curr > sum)
        return false;

    if (idx >= prevNum.size()) {
        return curr == sum && greater;
    }

    if (dp[idx][curr][greater] != -1)
        return dp[idx][curr][greater];

    dp[idx][curr][greater] = 0;
    int st = greater ? 0 : prevNum[idx] - '0';
    for (int i = st; i <= 9; i++) {
        bool flag = solve(idx + 1, curr + i, greater || (i > st));

        if (flag) {  //it will be builded in reverse order while the recursion return
            s.push_back(i+'0');
            return true;    // retuun used > as no need to try any larger number(we need the mini), also no need to cache true (inside the dp) because once this path ok, we wont revisit again(we end the function by return).
        }
    }
    dp[idx][curr][greater] = false;
    return dp[idx][curr][greater];

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    //cin >> t;
    while (t--) { 
        int n;
        cin >> n;
        prevNum=string(N - 1, '0');
        for (int i = 0; i < n; i++) {
            cin >> sum;
            memset(dp, -1, sizeof dp);
            s.clear();

            solve();
            prevNum = s;
            reverse(prevNum.begin(), prevNum.end());
            
            while (s.back() == '0') { //we builded it in reverse order.therfore, leading zeros appear at the end 
                s.pop_back();
            }
            reverse(s.begin(), s.end());
            cout << s << endl;

        }
    }
    return 0;
} 
