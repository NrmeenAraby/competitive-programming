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
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int mex = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] - a[i] == mex)
                    mex++;
            }
            mx = max(mx, mex);
        }
        cout << mx << "\n";
    }
    return 0;
}
