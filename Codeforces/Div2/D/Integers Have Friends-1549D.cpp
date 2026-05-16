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
vector<vector<ll>>sp;
vector<ll>lg;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void preLog(int n) { //O(n)
    lg.resize(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}
ll merge(ll a, ll b) {
    return gcd(a, b);
}
void buildSP(vector<ll>&v) {  //nlogn
    int n = v.size();
    sp.resize(n, vector<ll>(25,0));
    for (int i = 0; i < n; i++) {
        sp[i][0] = v[i];
    }
    for (int pw = 1; (1 << pw) <= n; pw++) {
        for (int i = 0;  (i + (1 << pw)) <= n; i++) {
            sp[i][pw] = merge(sp[i][pw - 1], sp[i + (1 << (pw-1))][pw - 1]);
        }
    }
}
ll query(int l,int r) { //O(1)
    int sz = r - l + 1;
    ll pw = lg[sz];      //greatest power that gives length less than or equal r
    return merge(sp[l][pw], sp[r - (1 << pw) + 1][pw]);
}
int main() {
    //elements that have the same m, the difference between each of them is divisible by m
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

        if (n == 1) {
            cout << 1 << endl;
        }
        else {
            vector<ll>diff(n - 1);
            for (int i = 0; i < n - 1; i++) {
                diff[i] = abs(v[i] - v[i + 1]);
            }
            n = diff.size();
            preLog(n);
            buildSP(diff);
            int ans = 0;
            for (int l = 0; l < n; l++) {
                int r = l;
                while (r < n) {
                    int s = r, end = n - 1, pos = r;
                    ll g = query(l, r);
                    while (s <= end) {
                        int md = s + (end - s) / 2;
                        if (query(l, md) == g) {
                            pos = md;
                            s = md + 1;
                        }
                        else {
                            end = md - 1;
                        }
                    }
                    if (g > 1) {
                        int length = pos - l + 1;
                        ans = max(ans, length);
                    }
                    r = pos + 1;
                }
            }
            cout << ans + 1 << endl;
        }
    }
    
    return 0;
}
