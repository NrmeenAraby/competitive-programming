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
        vector<int>h(n);
        map<int, int>freq;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
            freq[h[i]]++;
        }
        sort(h.begin(), h.end());
        int st = 0, en = n - 1;
        vector<int>ans(n);
        for (int i = 0; i < n; i+=2) {
            ans[st++] = h[i];
            if (i + 1 < n)
                ans[en--] = h[i + 1];
        }
        int k = 0;
        for (auto num : freq) {
            k += min(num.second, 2);
        }
        cout << k << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
