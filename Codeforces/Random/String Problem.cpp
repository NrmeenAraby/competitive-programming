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
    //cin >> t;
    while (t--) {
        string s,st;
        cin >> s >> st;
        
            vector<vector<int>>v(26, vector<int>(26));
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (i != j) {
                        v[i][j] = 1e9;
                    }
                }
            }
            int n;
            cin >> n;
            char a, b;
            int w;
            for (int i = 0; i < n; i++) {
                cin >> a >> b >> w;
                int vala = a - 'a', valb = b - 'a';
                v[vala][valb] =min( v[vala][valb], w);
            }
            if (s.size() != st.size()) {
                cout << -1 << endl;
            }
            else {
                for (int mid = 0; mid < 26; mid++) {
                    for (int st = 0; st < 26; st++) {
                        for (int end = 0; end < 26; end++) {
                            v[st][end] = min(v[st][end], v[st][mid] + v[mid][end]);
                        }
                    }
                }
                ll sum = 0, flag = 0;
                string res;
                for (int i = 0; i < s.size(); i++) {
                    if (s[i] != st[i]) {
                        int vals = s[i] - 'a', valst = st[i] - 'a';
                     
                        char minCommon;
                        int mnCost = 1e9;
                        for (char i = 'a'; i <= 'z'; i++) {
                            int val = i - 'a';
                            if (v[vals][val] != 1e9 && v[valst][val] != 1e9) {
                                if (v[vals][val] + v[valst][val] < mnCost) {
                                    mnCost = v[vals][val] + v[valst][val];
                                    minCommon = i;
                                }
                            }
                        }
                        if (v[vals][valst] == 1e9 && v[valst][vals] == 1e9 && mnCost==1e9) { //there is no way to make these letters identical
                            flag = 1;
                            break;
                        }
                        sum += min(mnCost,min(v[vals][valst], v[valst][vals]));
                        if (mnCost < v[vals][valst] && mnCost < v[valst][vals]) {
                            res.push_back(minCommon);
                        }
                        else if (v[vals][valst] < v[valst][vals]) {
                            res.push_back(st[i]);
                        }
                        else {
                            res.push_back(s[i]);
                        }
                    }
                    else {
                        res.push_back(s[i]);
                    }
                }
                if (flag)
                {
                    cout << -1 << endl;
                }
                else {
                    cout << sum << endl;
                    cout << res << "\n";
                }
            }
        }
    
    return 0;
}
