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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b || a == c || b == c) {
            cout << 0 << endl;
        }
        else {
            int mn = min(a, min(b, c));
            int mx = max(a, max(b, c));
            int ans;
            if (a != mn && a != mx) {
                ans = min(abs(a - mn), abs(a - mx));
            }
            else if (b != mn && b != mx) {
                ans = min(abs(b - mn), abs(b - mx));
            }
            else {
                ans = min(abs(c - mn), abs(c - mx));
            }
            cout << ans << endl;
        }
    }
    return 0;
}
