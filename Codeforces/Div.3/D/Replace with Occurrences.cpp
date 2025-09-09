#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MOD = 32768;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        map<int, int>freq;
        for (int i = 0; i < n; i++) {
            freq[b[i]]++;
        }
        long long sum = 0;
        int flag = 0;
        for (auto item : freq) {
            if (item.first == 1) {
                sum += item.second;
            }
            else {
                if (item.second % item.first == 0)
                {
                    sum += item.second;
                }
                else {
                    flag = 1;
                }
            }
        }
        if (sum != n || flag) {
            cout << -1 << "\n";
        }
        else {
            map<int, vector<pair<int, int>>>mp;
            int cntr = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] == 1) {
                    cntr++;
                    cout << cntr << " ";
                }
                else {
                    if (mp[b[i]].empty()) {
                        cntr++;
                        cout << cntr << " ";
                        mp[b[i]].push_back({ cntr, b[i] - 1 });
                    }
                    else {
                        cout << mp[b[i]].back().first<<" ";
                        mp[b[i]].back().second--;
                        if (mp[b[i]].back().second == 0)
                            mp[b[i]].pop_back();
                    }

                }
            }
        }
    }
    return 0;
}
 
