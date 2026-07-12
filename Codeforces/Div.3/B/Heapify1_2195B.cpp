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

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll sub(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

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
        for (int i = 0; i < n; i++) {
            cin >> a[i];           
        }
        int flag = 0;
        for (int i = 1; i <= n; i+=2) { //every component like:{1,2,4,8,..} starts at an odd index
            vector<int>pos, vals;
                int x = i;
                while ( x <= n) {
                    vals.push_back(a[x - 1]);
                    pos.push_back(x);
                    x *= 2;
                }
               // sort(pos.begin(), pos.end()); //no need, it is always sorted
                sort(vals.begin(), vals.end());
                for (int k = 0; k < pos.size(); k++) {
                    if (pos[k] != vals[k]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
        }

        if (flag) {
            cout << "No\n";
        }
        else {
            cout << "yes\n";
        }
    }
    return 0;
}
