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

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        ll f, a, b;
        cin >> n >> f >> a >> b;
        vector<ll>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ll sum = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            ll mn = min((v[i] - prev) * a, b);
            sum += mn;
            prev = v[i];
        }
        if (sum >= f)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
