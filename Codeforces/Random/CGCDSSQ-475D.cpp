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
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
vector<ll>lg;
void preLog(ll n) {
    lg.resize(n+1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
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

ll getGCD(ll l, ll r) { 
    ll sz = r - l + 1;
    ll pw = lg[sz]; //greatest power that gives length less than or equal r 
    return gcd(spGCD[l][pw], spGCD[r - (1 << pw) + 1][pw]);
}


int main() {
    // num of distincit gcds that may exist in some array doesnt exceed log(max num) because each time it loses some prime factor (since we devide by 2 at least)(gcd either stay the same or smaller)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int q;
        cin >> q;
        preLog(n);
        buildSpGCD(v);
        map<ll, ll>mp;
        for (int l = 0; l < n; l++) { 
            int r = l;
            while (r < n) { //log(max) = log(1e9)  
                int s = r, end = n - 1, g = getGCD(l, r), pos = r;
                while (s <= end) {
                    int md = s + (end - s) / 2;
                    if (getGCD(l, md) == g) {
                        pos = md;
                        s = md + 1;
                    }
                    else {
                        end = md - 1;
                    }
                }
                mp[g] += (pos - r + 1);
                r = pos + 1;
            }
        }
        int x;
        while (q--) {
            cin >> x;
            cout << mp[x] << "\n";
                
        }
    }
    
    return 0;
}
