#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    int t,n,k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        map<int, int>mp;
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mp[v[i]]++;
        }
        int score = 0;
        for (int i = 0; i < n; i++) {
            if (mp[v[i]]) {
                mp[v[i]]--;
                int b = k - v[i];
                if (mp[b]) {
                    mp[b]--;
                    score++;
                }
            }
        }
        cout << score << "\n";
    }
    return 0;
}
