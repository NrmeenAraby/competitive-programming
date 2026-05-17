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
        vector<pair<int,int>>prefMin(n);
        prefMin[0] = { get<1>(v[0]), get<2>(v[0])}; //num, idx
        for (int i = 1; i < n; i++) {
            if (prefMin[i - 1].first < get<1>(v[i])) {
                prefMin[i] = { prefMin[i - 1].first, prefMin[i - 1].second };
            }
            else {
                prefMin[i] = { get<1>(v[i]) ,get<2>(v[i]) };
            }
        }
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
                if (prefMin[pos].first < y) {
                    cout << prefMin[pos].second+1 << " ";
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
