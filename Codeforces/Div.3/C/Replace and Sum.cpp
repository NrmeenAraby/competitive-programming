#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <numeric>
#include<queue>
#include<array>
using namespace std;
const long long MAX = 1e18;


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,q;
        cin >> n>>q;
        vector<int>a(n),b(n),mxV(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<pair<int, int>>qs;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            qs.push_back({ l,r });
        }
        mxV[n - 1] = max(a[n-1], b[n-1]);
        for (int i = n - 2; i >= 0; i--) {
            mxV[i] = max(mxV[i + 1], max(a[i], b[i]));
        }
        for (int i = 1; i < n; i++) {
            mxV[i] += mxV[i - 1];
        }
      
        for (int i = 0; i < qs.size(); i++) {
            int l = qs[i].first, r = qs[i].second;
            if (l > 0) {
                cout << mxV[r] - mxV[l - 1] << " ";
            }
            else {
                cout << mxV[r] << " ";
            }
        }
        
        cout << endl;
    }
    return 0;
}
