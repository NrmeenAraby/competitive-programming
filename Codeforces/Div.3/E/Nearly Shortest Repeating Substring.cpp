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
    // buildFact();
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int>divs;
        divs = get_divisors(n);
        sort(divs.begin(), divs.end());
        int k ;
        for (int i = 0; i < divs.size(); i++) {
            k = divs[i];
            string baseP,baseS,subP,subS;
            for (int j = 0; j < k; j++) { //prefix (first k letters)
                subP.push_back(s[j]);
            }
            baseP = subP;
            for (int j = n-k; j <n; j++) { //try the suffix also(last k letters) as maybe the only different letter was in the prefix
                subS.push_back(s[j]);
            }
            baseS = subS;
         /*   cout << "K " << k << endl;
            cout << "SubS " << subS << endl;*/
            int iter = n / k;
            for (int j = 1; j <= iter-1; j ++) {
                subP.append(baseP);
                subS.append(baseS);
            }

            int cntrP = 0,cntrS=0;
            for (int j = 0; j < n; j++) {
                if (subP[j] != s[j])
                    cntrP++;
                if (subS[j] != s[j])
                    cntrS++;
            }
            if (cntrP<= 1 ||cntrS<=1) {
                break;
            }
        }
        cout << k << endl;
    }
    return 0;
}
