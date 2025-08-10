#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e7 + 7;
int dp[MAX];
int main() {
    int t, n,m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        map<int, int>who;
        vector<vector<int>>v(n);
        int x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;
                v[i].push_back(x);
                who[x] = i+1;
            }
        }
        for (auto& row : v) {
            sort(row.begin(), row.end());
        }
        int flag = 0;
        if (m != 1) {   
            for (int i = 0; i < n; i++) {
                for (int j = 1; j < n; j++) {
                    if (v[i][j] - v[i][j - 1] != n) {
                        flag = 1;
                    }
                }
            }
        }
        if (flag) {
            cout << -1 << "\n";
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << who[i] << " ";
            }
            cout << endl;
        }

    }
    return 0;
}
