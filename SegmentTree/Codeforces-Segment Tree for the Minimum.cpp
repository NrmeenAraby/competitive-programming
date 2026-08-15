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
struct SegmentTree {
private:
#define L 2*node+1   //to access the right node value from the array of size 2n
#define R 2*node+2
#define mid (l+r)/2
    int sz;
    vector<ll>seg;
    ll merge(ll a,ll b) {
        return min(a, b);
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
            seg[node] = val;
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
    ll query(int l, int r, int node, int lq, int rq) {  //log n
        if (r<lq || l>rq) {  
            return LLONG_MAX;          //cahnge the return  value as needed 
        }
        if (l >= lq && r <= rq) {
            return seg[node];
        }
        ll left = query(l, mid, L, lq, rq);
        ll right = query(mid + 1, r, R, lq, rq);
        return merge(left , right);
    }
public:
    SegmentTree(vector<ll>& arr) {
        sz = 1;
        int n = arr.size();
        while (sz < n)sz *= 2; //to grt fitst sz of power 2 greater than or equal n
        seg.resize(2*sz);  //seg size is 2n
        build(0, sz - 1, 0, arr);  //first call on the root node, whose range covers the entire array(0:sz-1)
    }
    void update(int idx, ll val) {
        update(0, sz - 1, 0, idx, val);
    }
    ll query(int lq, int rq) {
        return query(0, sz - 1, 0, lq, rq);
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
        int n, q;
        cin >> n >> q;
        vector<ll>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        SegmentTree segT(v);
        int op;
        while (q--) {
            cin >> op;
            int idx;
            ll val;
            if (op == 1) {
                cin >> idx >> val;
                segT.update(idx, val);
            }
            else {
                int lq, rq;
                cin >> lq>> rq;
                cout << segT.query(lq, rq - 1)<<endl;
            }
        }
    }
    return 0;
} 
