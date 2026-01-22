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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int>a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        string sk;
        cin >> sk;
        sort(b.begin(), b.end());
        deque<pair<int, int>>r, l;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(b.begin(), b.end(), a[i]);
            if (it != b.begin()) {
                it--;
                int diff = a[i] - *it;
                l.push_back({ diff,i });
            }
            it = upper_bound(b.begin(), b.end(), a[i]);
            if (it != b.end()) {
                int diff = *it - a[i];
                r.push_back({ diff,i });
            }
        }
        sort(r.begin(), r.end());
        sort(l.begin(), l.end());
        int cumR = 0, cumL = 0;
        int ans = n;
        map<int, int>killed; // to prevent over counting(so for ex: if some robot has been killed because of the left direction >> it must be removed also from the r deque without recounting)
        for (int i = 0; i < k; i++) {
            if (sk[i] == 'L') {
                cumR++;
                cumL--;
                while (!l.empty() && l.front().first + cumL <= 0) {
                    if (killed[l.front().second] != 1) {
                        ans --;
                        killed[l.front().second] = 1;
                    }
                    l.pop_front();

                }
            }
            else {
                cumR--;
                cumL++;
                while (!r.empty() && r.front().first + cumR <= 0) {
                    if (killed[r.front().second] != 1) {
                        ans --;
                        killed[r.front().second] = 1;
                    }
                    r.pop_front();

                }
            }
            ans = max(ans, 0); //to prevent -ve vals
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}
