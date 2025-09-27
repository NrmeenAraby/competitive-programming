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
        vector<int>v(n);
        vector<long long>prefix(n + 1);
        prefix[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            prefix[i + 1] = prefix[i] + v[i];
        }
        map<long long, int>mp;
        long long ans = 0;
        for (int i = 0; i < n + 1; i++) {
            mp[prefix[i]]++;
            if (mp[prefix[i]] > 1) {
                ans++;
                mp.clear();
                mp[prefix[i]]++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
