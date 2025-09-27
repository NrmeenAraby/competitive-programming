#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;
int main() {
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>>v(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        long long ans = 0;
        int mn = 0;
        for (int i = n - 1; i >= 0; i--) {
            int curri = i;
            for (int j = 0; j < n - i; j++) {
                mn = min(mn, v[curri][j]);
                curri++;
            }
            if (mn < 0)
            {
                ans += (-1 * mn);
                mn = 0;
            }
        }
        
        for (int j = 1; j < n; j++) {
            int currj = j;
            for (int i = 0; i < n - j; i++) {
                mn = min(mn, v[i][currj]);
                currj++;
            }
            if (mn < 0)
            {
                ans += (-1 * mn);
                mn = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
