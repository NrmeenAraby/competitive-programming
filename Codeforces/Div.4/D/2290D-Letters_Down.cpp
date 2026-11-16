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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (char c = 'z'; c >= 'b'; c--) {
            int flag = 0;

            for (int i = 0; i < n / 2; i++) {
                if (s[i] != s[n - 1 - i]) {
                    if (s[i] == c || s[n - 1 - i] == c) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag) {
                for (auto& ch : s) {
                    if (ch == c)
                        ch--;
                }
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
