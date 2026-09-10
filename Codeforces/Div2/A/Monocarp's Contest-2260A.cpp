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
const int MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0)
                zeros++;
        }
        if (zeros < 2)
            cout << -1 << endl;
        else {
            int ops = 0;
            if (a[0] != 0)
                ops++;
            if (a[n - 1] != 0)
                ops++;

            cout << ops << endl;
        }
    }
    return 0;
}
