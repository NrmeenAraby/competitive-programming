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
vector<vector<pair<int,int>>>sp;
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
pair<int,int> merge(pair<int,int> a, pair<int,int> b) {
    return min(a, b);
}
void buildSP(vector<tuple<int,int,int>>& v) {  //nlogn
    int n = v.size();
    sp.resize(n, vector<pair<int,int>>(25));
    for (int i = 0; i < n; i++) {
        sp[i][0] = { get<1>(v[i]),get<2>(v[i]) };  //num,idx
    }
    for (int pw = 1; (1 << pw) <= n; pw++) {
        for (int i = 0; (i + (1 << pw)) <= n; i++) {
            sp[i][pw] = merge(sp[i][pw - 1], sp[i + (1 << (pw - 1))][pw - 1]);
        }
    }
}
pair<int,int> query(int l, int r) { //O(1)
    int sz = r - l + 1;
    ll pw = lg[sz];      //greatest power that gives length less than or equal r
    return merge(sp[l][pw], sp[r - (1 << pw) + 1][pw]);
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
        vector<tuple<int, int, int>>v(n),og(n);
        int h, w;
        for (int i = 0; i < n; i++) {
            cin >> h >> w;  
            int mn = min(h, w);  /*as we can satisfy any of the 2 rules(hj<hi, wj<wi) or (hj<wi, wj<hi),
            so doing this normalization beteer than repeatig the algo twice(once to check for the first rule and if not satisified
            we have to apply the algo again for the second condition)*/
            int mx = max(h, w);
            og[i] = { mn,mx, i };
            v[i] = { mn,mx, i };
        }
        sort(v.begin(), v.end()); // sort depending on the first num in the tuple
        preLog(n);
        buildSP(v);
        int pos = -1;
        for (int i = 0; i < n; i++) {
            int x = get<0>(og[i]);
            int y = get<1>(og[i]);
            int st = 0, end = n - 1;
            int pos = -1;
            while (st <= end) {
                int md = st + (end - st) / 2;
                if (get<0>(v[md]) < x) {
                    pos = md;
                    st = md + 1;
                }
                else {
                    end = md - 1;
                }
            }
            if (pos == -1) {
                cout << -1 << " ";
            }
            else {
                pair<int, int> res = query(0, pos);
                if (res.first < y) {
                    cout << res.second + 1 << " ";
                }
                else {
                    cout << -1 << " ";
                }
            }
        }
        cout << endl;
    }   
    return 0;
}
