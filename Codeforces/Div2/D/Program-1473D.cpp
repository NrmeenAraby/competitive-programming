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
vector<vector<ll>>spMax;
void buildSpMax(vector<int>& v) { //nlogn
    int n = v.size();
    spMax.resize(n, vector<ll>(22));
    for (int i = 0; i < n; i++) {
        spMax[i][0] = v[i];
    }
    for (int pw = 1; (1 << pw) <= n; pw++) {
        for (int i = 0; i + (1 << pw) <= n; i++) {
            spMax[i][pw] = max(spMax[i][pw - 1], spMax[i + (1 << (pw - 1))][pw - 1]);
        }
    }
}

ll getMax(int l, int r) { //O(1)
    int sz = r - l + 1;
    int pw = lg[sz]; //greatest power that gives length less than or equal r 
    return max(spMax[l][pw], spMax[r - (1 << pw) + 1][pw]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int>prfx(n + 1);
        prfx[0] = 0;
        for (int i = 1; i <= n; i++) {
            prfx[i] = prfx[i-1];
            if (s[i-1] == '+')
                prfx[i]++;
            else {
                prfx[i]--;
            }
        }
        int l, r;
        preLog(n);
        buildSpMax(prfx);
        buildSpMin(prfx);
        for (int q = 1; q <= m; q++) {
            cin >> l >> r;
            int mnpre = getMin(0, l - 1);
            int mxpre = getMax(0, l-1);
            
            int mnsuf = 1e9, mxsuf = 0;
            if (r + 1 <= n) {
                mnsuf = getMin(r + 1, n) - (prfx[r] - prfx[l - 1]);
                mxsuf = getMax(r + 1, n) - (prfx[r] - prfx[l - 1]);
            }
            int mn = min(mnpre, mnsuf);
            int mx = max(mxpre, mxsuf);
            cout << mx - mn +1<< endl;
        }
    }

    
    return 0;
}
