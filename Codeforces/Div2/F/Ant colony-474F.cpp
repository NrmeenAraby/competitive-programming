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
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
vector<ll>lg;
vector<vector<ll>>spMin;
void preLog(int n) {
    lg.resize(n+1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}
void buildSpMin(vector<int>&v) { //nlogn
    int n = v.size();
    spMin.resize(n, vector<ll>(22));
    for (int i = 0; i < n; i++) {
        spMin[i][0] = v[i];
    }
    for (int pw = 1; (1 << pw) <= n; pw++) {
        for (int i = 0; i+(1<<pw) <= n; i++) {
            spMin[i][pw] = min(spMin[i][pw - 1], spMin[i + (1 << (pw-1))][pw - 1]);
        }
    }


}
ll getMin(int l, int r) { //O(1)
    int sz = r - l + 1;
    int pw = lg[sz]; //greatest power that gives length less than or equal r 
    return min(spMin[l][pw], spMin[r - (1 << pw) + 1][pw]);
}
vector<vector<ll>>spGCD;
void buildSpGCD(vector<int>& v) { //nlogn
    int n = v.size();
    spGCD.resize(n, vector<ll>(22));
    for (int i = 0; i < n; i++) {
        spGCD[i][0] = v[i];
    }
    for (int pw = 1; (1 << pw) <= n; pw++) {
        for (int i = 0; i + (1 << pw) <= n; i++) {
            spGCD[i][pw] = gcd(spGCD[i][pw - 1], spGCD[i + (1 << (pw - 1))][pw - 1]);
        }
    }
}

ll getGCD(int l, int r) { //O(1)
    int sz = r - l + 1;
    int pw = lg[sz]; //greatest power that gives length less than or equal r 
    return gcd(spGCD[l][pw], spGCD[r - (1 << pw) + 1][pw]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n ;
        vector<int>v(n);
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mp[v[i]].push_back(i);
        }

        preLog(n);
        buildSpGCD(v);
        buildSpMin(v);
        int q, l, r;
        cin >> q;
        for (int i = 1; i <= q; i++) {
            cin >> l >> r;
            l--, r--;
            int mn = getMin(l, r);
            int gc = getGCD(l, r);
            if (mn != gc) {
                cout << r - l+1 << endl;
            }
            else {
                int diff = upper_bound(mp[mn].begin(), mp[mn].end(), r) - lower_bound(mp[mn].begin(), mp[mn].end(), l);
                cout << (r - l+1) - diff << endl;
            }
        }
    }

    
    return 0;
}
