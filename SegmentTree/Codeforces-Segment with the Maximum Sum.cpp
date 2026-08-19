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
#define L 2*node+1   //to access the right node value from the array of size 2n
#define R 2*node+2
#define mid (l+r)/2

    int sz;
    vector<Node>seg;
    Node merge(Node lft,Node right) {
        Node node;
        node.sum = lft.sum + right.sum;
        node.mxPrefx = max(lft.mxPrefx, lft.sum + right.mxPrefx);
        node.mxSufx = max(right.mxSufx, right.sum + lft.mxSufx);
        node.mx = max(lft.mx, right.mx); node.mx = max(node.mx, lft.mxSufx + right.mxPrefx);
        return node;
    }
    void build(int l, int r, int node, vector<ll>& arr) {
        if (l == r) {
            if (l < arr.size()) {  // to avoid out of bound as the arr size is less than the seg size
                seg[node].sum =arr[l];
                seg[node].mxPrefx = max(0ll, arr[l]); // max betweeen 0 and val because of they said :"this segment may be empty (so the sum on it will be equal to 0)."
                seg[node].mxSufx = max(0ll, arr[l]);
                seg[node].mx = max(0ll, arr[l]);
            }
            return;
        }
        build(l, mid, L, arr);   //left
        build(mid + 1, r, R, arr);  //right
        seg[node] = merge(seg[L],seg[R]);
    }
    void update(int l, int r, int node, int idx, ll val) {  //log n
        if (l == r) {
            seg[node].sum =val;
            seg[node].mxPrefx = max(0ll, val); // max betweeen 0 and val because of they said :"this segment may be empty (so the sum on it will be equal to 0)."
            seg[node].mxSufx = max(0ll, val);
            seg[node].mx = max(0ll, val);
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
    Node query(int l, int r, int node, int lq, int rq) {  //log n
        if (r<lq || l>rq) {  
            return Node(0,0,0,0);          //cahnge the return  value as needed 
        }
        if (l >= lq && r <= rq) {
            return seg[node];
        }
        Node left= query(l, mid, L, lq, rq);
        Node right = query(mid + 1, r, R, lq, rq);
        return merge(left , right);
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
    Node query(int lq, int rq) {
        return query(0, sz - 1, 0, lq, rq);
    }

};

int main() {
    // to make them equal, ur k must be large enough to make the shortest tower reach the height of the tallest one
    // notice that xi must be at least 1, so a cube must be added to the tallest one 
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
        vector<ll>ans;
        ans.push_back(segT.query(0, n - 1).mx);
        while (m--) {
            int idx;
            ll val;
            cin >> idx >> val;
            segT.update(idx, val);
            ans.push_back(segT.query(0, n - 1).mx);
        }
        for (ll show : ans) {
            cout << show << endl;
        }
    }
    return 0;
} 
