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
const int INF =1e9;
const int MOD = 1e9 + 7;

int main() {
    /*we can achieve any combination of final segment signs by choosing the right set of posts,
     so we can independently maximize each segment's contribution by taking the absolute value of its sum.*/
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll>a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<ll>prfx(n+1);
        prfx[0] = 0; // because of this 0 pushed to b
        for (int i = 1; i <= n; i++) {
            prfx[i] = prfx[i - 1] + a[i-1];
        }

        b.push_back(0); // size of b is increased by 1
        sort(b.begin(), b.end());
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += abs(prfx[b[i]] - prfx[b[i - 1]]);
        }
        ans+= (prfx[n] - prfx[b[m]]);
        cout << ans << endl;
    }
    return 0;
}
