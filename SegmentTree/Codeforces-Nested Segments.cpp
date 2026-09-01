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
const int MOD = 1e9 + 7;
struct SegmentTree {
private:
#define L 2*node+1   //to access the correct node value from the array of size 2n
#define R 2*node+2
#define mid (l+r)/2

    int sz;
    vector<ll>seg;
    ll merge(ll a, ll b) {
        return a + b;
    }
    void build(int l, int r, int node, vector<ll>& arr) {
        if (l == r) {
            if (l < arr.size()) {  // to avoid out of bound as the arr size is less than the seg size
                seg[node] = 0;
            }
            return;
        }
        build(l, mid, L, arr);   //left
        build(mid + 1, r, R, arr);  //right
        seg[node] = merge(seg[L], seg[R]);
    }
    void update(int l, int r, int node, ll idx, ll val) {  //log n
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
        seg[node] = merge(seg[L], seg[R]);
    }

    ll query(int l, int r, int node, int lq, int rq) {
        if (r<lq || l>rq)
            return 0;
        if (l >= lq && r <= rq)
            return seg[node];
        ll lft = query(l, mid, L, lq, rq);
        ll right = query(mid + 1, r, R, lq, rq);
        return lft + right;
    }


public:
    SegmentTree(vector<ll>& arr) {
        sz = 1;
        int n = arr.size();
        while (sz < n)sz *= 2; //to get first sz of power 2 greater than or equal n
        seg.resize(2 * sz);  //seg size is 2n
        build(0, sz - 1, 0, arr);  //first call on the root node, whose range covers the entire array(0:sz-1)
    }
    void update(ll idx, ll val) {
        update(0, sz - 1, 0, idx, val);
    }
    ll query(int l,int r) {
        return query(0, sz - 1, 0, l,r);
    }


};

int main() {
    // we start with a segment tree of zeros, we update with 1 only when we find the second occurence of the number
    // as u go from left to right, so it is guaranteed that u will count only the complete segments inside ur current segment 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll>a(2*n);
        SegmentTree segT(a);
        vector<int>first_occurence(n+1,-1);
        vector<int>ans(n + 1);
        int x;
        for (int i = 0; i < 2*n; i++) {
            cin >> x;
            if (first_occurence[x] != -1) {
                int l = first_occurence[x];
                int r = i;
                ans[x] = segT.query(l + 1, r - 1);
                segT.update(l, 1);
            }
            else {
                first_occurence[x] = i;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i]<<" ";
        }

    }
    return 0;
}
