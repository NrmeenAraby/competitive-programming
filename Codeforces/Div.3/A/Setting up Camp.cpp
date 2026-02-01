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
    //cout << fixed << setprecision(10);
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int need = 0;
        if (b % 3 != 0) {
            need= 3 - (b % 3);
        }

        if (need > c)
            cout << -1 << "\n";
        else {
            int ans = a;
            b += need;
            c -= need;
            ans += (b / 3);
            ans += (c / 3);
            if (c % 3 != 0)
                ans++;
            cout << ans << "\n";
        }
    }

    return 0;
}
