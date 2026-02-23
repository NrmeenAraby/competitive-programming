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
vector<ll>lg;
vector<vector<ll>>sp;
void preLog(int n) {
    lg.resize(n+1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}
void buildSp(vector<int>&v) { //nlogn
    int n = v.size();
    sp.resize(n, vector<ll>(22));
    for (int i = 0; i < n; i++) {
        sp[i][0] = v[i];
    }
    for (int pw = 1; (1 << pw) <= n; pw++) {
        for (int i = 0; i+(1<<pw) <= n; i++) {
            sp[i][pw] = min(sp[i][pw - 1], sp[i + (1 << (pw-1))][pw - 1]);
        }
    }

}
ll get(int l, int r) { //O(1)
    int sz = r - l + 1;
    int pw = lg[sz]; //greatest power that gives length less than or equal r 
    return min(sp[l][pw], sp[r - (1 << pw) + 1][pw]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,q;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> q;
    preLog(n);
    buildSp(v);
    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << get(l, r)<<endl; // zero based
    }
    
    return 0;
}
