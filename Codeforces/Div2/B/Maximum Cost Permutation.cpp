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
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;
int mul(int a, int b) {
    return (1ll * a * b) % MOD;
}
vector<ll>fact(1e5 + 5);
void buildFact() {
    fact[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
}
ll binary_exp(ll base, ll p) {
    ll ret = 1;
    while (p) {
        if (p % 2 != 0) {
            ret = mul(ret, base);
        }
        base = mul(base, base);
        p /= 2;
    }
    return ret;
}
int modInverse(int x) {
    return binary_exp(x, MOD - 2);
}
int ncr(int n, int r) {
    if (n < r)
        return 0;
    return mul(fact[n], modInverse(mul(fact[r], fact[n - r])));
}
bool isMnwara(int mask, int bit) {
    return (mask >> bit) & 1;
}
vector<int> get_divisors(int n) {
    vector<int>divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (n / i != i) {
                divs.push_back(n/i);
            }
        }
    }
    return divs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int>check(n + 1);
        for (int i = 0; i < n; i++) {
            check[v[i]] = 1;
        }
        deque<int>need;
        for (int i = 1; i <= n; i++) {
            if (check[i] == 0)
                need.push_back(i);  //so it is sorted
        }
        if (!need.empty()) {
            reverse(need.begin(), need.end());
            for (int i = 0; i < n; i++) {
                if (v[i] == 0) {
                    v[i] = need.front();
                    need.pop_front();
                }
            }
        }
        //for (auto tmp : v)
        //    cout << tmp << " ";
        //cout << endl;

        vector<int>pos(n + 1);
        for (int i = 0; i < n; i++) {
            pos[v[i]] = i + 1;
            
        }

        int l = -1, r = -1;
        for (int i = 1; i <= n; i++) {
           // cout << pos[i] << " ";
            if (i != pos[i] ) {
                if (l == -1) {
                    l = i;
                }
                else {
                    r = i;
                }
            }
        }
        if (l == -1)
            cout << 0 << endl;
        else {
            cout << r - l + 1 << endl;
        }

    }
    return 0;
}
