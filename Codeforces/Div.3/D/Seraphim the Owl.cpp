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
#include <iomanip>
using namespace std;
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;

#define ll  long long

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll>a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        ll sum = 0;
        for (int i = n - 1; i > m-1; i--) {
            sum += min(a[i], b[i]);
        }
        ll tmpSum=0;
        vector<ll>may(m);
        for (int i = m-1; i >= 1; i--) {  //m-1 as we r 0-based while m is 1-based
            may[i] = tmpSum + a[i];
            tmpSum += min(a[i], b[i]);
        }
        may[0] = tmpSum + a[0];
        ll mn = LLONG_MAX;
        for (int i = 0; i < m; i++) {
            mn = min(mn, may[i]);
        }
        ll ans = sum + mn;
        cout << ans << "\n";
    }

    return 0;
}
