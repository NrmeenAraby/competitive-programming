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
const int MAX = 2e5 + 5;
const int MOD = 1e9+7;
struct Node {
    ll sum;
    ll mxPrefx;
    ll mxSufx;
    ll mx;
    Node(){}
    Node(ll sum,ll mxPrfx,ll mxSufx,ll mx) {
        this->sum = sum;
        this->mxPrefx = mxPrfx;
        this->mxSufx = mxSufx;
        this->mx = mx;
    }

};
struct SegmentTree {
private:
#define L 2*node+1   //to access the correct node value from the array of size 2n
#define R 2*node+2
#define mid (l+r)/2

    int sz;
    vector<ll>seg;
    ll merge(ll a,ll b) {
        return a + b;
    }
    void build(int l, int r, int node, vector<ll>& arr) {
        if (l == r) {
            if (l < arr.size()) {  // to avoid out of bound as the arr size is less than the seg size
                seg[node] = arr[l];
            }
            return;
        }
        build(l, mid, L, arr);   //left
        build(mid + 1, r, R, arr);  //right
        seg[node] = merge(seg[L],seg[R]);
    }
    void update(int l, int r, int node, int idx, ll val) {  //log n
        if (l == r) {
            seg[node]=val;
            return;
        }
        if (idx <= mid) { //go left
            update(l, mid, L, idx, val);
        }
        else { // go right
            update(mid + 1, r, R, idx, val);
        }
        seg[node] = merge(seg[L] , seg[R]);
    }
    int find(int l, int r, int node, int k) {
        if (l == r) {
            return l;
        }
        if (seg[L] < k) {
            find(mid + 1, r, R, k-seg[L]);
        }
        else {
            find(l, mid, L, k);
        }
    }


public:
    SegmentTree(vector<ll>& arr) {
        sz = 1;
        int n = arr.size();
        while (sz < n)sz *= 2; //to get first sz of power 2 greater than or equal n
        seg.resize(2*sz);  //seg size is 2n
        build(0, sz - 1, 0, arr);  //first call on the root node, whose range covers the entire array(0:sz-1)
    }
    void update(int idx, ll val) {
        update(0, sz - 1, 0, idx, val);
    }
    int find(int k) {
        return find(0, sz - 1, 0, k);
    }
  

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        SegmentTree segT(v);
        while (m--) {
            int op;
            cin >> op;
            if (op == 1) {
                int idx;
                cin >> idx;
                segT.update(idx, v[idx] == 0);
                v[idx] = (v[idx] == 0);
            }
            else {
                int k;
                cin >> k;
                k++;
                cout << segT.find(k)<<endl;
            }
        }

    }
    return 0;
} 
