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
    return (1ll*a * b) % MOD;
}
vector<ll>fact(1e5 + 5);
void buildFact() {
    fact[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        fact[i] = mul(fact[i - 1] , i);
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
    return mul(fact[n],  modInverse(mul(fact[r], fact[n - r])));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    buildFact();
    while (t--) {
        int a, b;
        cin >> a>>b;
        cout << mul(2, ncr(a - 1, b))<<endl;   //a-1 is the number of possible places where can change direction, for ex: if we L |R | L| L > length=4 but no. place where we can change is 3(between each char) 
    }                                   // so in how many ways we can do exactly b changes if we have a-1 place we can use to change 
    return 0;
}
