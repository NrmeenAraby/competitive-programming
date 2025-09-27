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
        vector<int>p(n + 1);
        vector<int>idx(n+1); //where are each num?(idx of the num)   (vector instead of map due to time complexity of accessing map )
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            idx[p[i]] = i;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i] != i && p[p[i]] != i) {
                int pi = p[i];
                p[idx[i]] = p[pi];
                idx[p[pi]] = idx[i];
                p[pi] = i;
                idx[i] = pi;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
