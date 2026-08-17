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

int main() {
    // to make them equal, ur k must be large enough to make the shortest tower reach the height of the tallest one
    // notice that xi must be at least 1, so a cube must be added to the tallest one 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n ;
        int mn = INT_MAX;
        int mx = 0;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        cout << mx - mn + 1 << endl;
    }
    return 0;
} 
