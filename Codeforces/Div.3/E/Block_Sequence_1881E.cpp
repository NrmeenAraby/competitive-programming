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
vector<int>a;
int dp[MAX];
int solve(int i=0) {
    if (i == n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    dp[i] = 2e9;
    dp[i] = min(dp[i], solve(i + 1) + 1);  //delete(leave) it
    if (i + a[i] + 1 <= n)
        dp[i] = min(dp[i], solve(i + a[i] + 1)); //take it(so move to the element after its block)

    return dp[i];
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
        a.clear();
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            dp[i] = -1;
        }
        cout << solve() << endl;
    }
    return 0;
}
