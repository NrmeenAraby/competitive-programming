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
        vector<ll>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ll tmp = 0;
        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > i + 1) {
                tmp += (v[i] - (i + 1));
            }
            else if (v[i] < i + 1) {
                int need = (i + 1) - v[i];
                if (need > tmp){
                    flag = false;
                    break;
                }
                else {
                    tmp -= need;
                }
            }
        }
        if (v[n - 1] + tmp < n)
            flag = false;

        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
