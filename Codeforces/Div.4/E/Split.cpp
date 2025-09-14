#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
 
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int>freq;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        int flag = 0;
        for (auto it : freq) {
            if (it.second % k != 0) {
                flag = 1;
            }
        }
        if (flag)
            cout << 0 << "\n";
        else {
            int l = 0;
            map<int, int>cnt;
            map<int, int>yadob;
            for (auto it : freq) {
                yadob[it.first] = freq[it.first] / k;
            }
            long long ans = 0;
            for (int r = 0; r < n; r++) {
                cnt[a[r]]++;
                while (l<r && cnt[a[r]]>yadob[a[r]]) {
                    cnt[a[l]]--;
                    l++;
                }
                ans += (r - l) + 1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
