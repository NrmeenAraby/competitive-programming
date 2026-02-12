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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    // buildFact();
    while (t--) {
        vector<int> binDec;
        for (int mask = 2; mask < (1 << 6); mask++) {  //generate all possible binary decimal up to 1e5
            int num = 0;
            for (int bit = 5; bit >= 0; bit--) {
                if (isMnwara(mask, bit)) {
                    num = (num * 10) + 1;
                }
                else {
                    if (num > 0)
                        num *= 10;
                }
            }
            if (num > 0 && num <= 100000)
                binDec.push_back(num);

        }
     
        int n;
        cin >> n;
        sort(binDec.begin(), binDec.end(), greater<>());
        for (int &num:binDec) {
            while (n % num == 0) {
                n /= num;
            }
        }
;
        if (n == 1)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
