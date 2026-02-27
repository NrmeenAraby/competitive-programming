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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;
    cin >> n>>k;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    preLog(n);
    buildSpMin(v);
    if (k == 1) {
        cout << getMin(0, n-1) << endl; 

    }
    else if (k == 2) {
        ll mx = max(getMin(0, n - 2), getMin(n - 1, n - 1));
        mx = max(mx, max(getMin(0, 0), getMin(1, n - 1)));
        cout << mx << endl;
    }
    else {
        cout << *max_element(v.begin(), v.end())<<endl; //as long as k>2, we can isolate this maxi element
    }
   

    
    return 0;
}
