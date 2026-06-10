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
const int MAX = 2e5+5;
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int>a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        ll diff = 0;
        for (int i = 0; i < n; i++) {
            diff += abs(a[i] - b[i+(m-n)]);   // i+(n-m) to get last n elements of b
        }
        if (n != m){
            ll mx = diff;
            for (int split =1; split <= n; split++) {  //take prefix of split elements from b and a suffix of n-split elements from b
                int bidx = m-(n - split); 
                diff -= abs(a[split-1] - b[bidx-1]);
                diff += abs(a[split-1] - b[split-1]);
                mx = max(mx, diff);
            }
            cout << mx << endl;
        }
        else {
            cout << diff << endl;

        }
    }
    return 0;
}
