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
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>>adj(n +1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> adj[i][j];
            }
        }

        vector<int>cancel(n);
        for (int i = 0; i < n; i++) {
            cin >> cancel[i];
        }
        reverse(cancel.begin(), cancel.end());
        vector<int>alive(n+1);
        vector<ll>ans;
        for (int i = 0; i < cancel.size(); i++) {
            int newMid = cancel[i];
            alive[newMid] = true;
            for (int st = 1; st <=n; st++) {
                for (int end = 1; end <=n; end++) {
                    int momkn = adj[st][newMid] + adj[newMid][end];
                    //int wmomkn = adj[v][mid] + adj[mid][u];    // nah, i guess this one is wrong as we are directed graph
                    adj[st][end] = min(adj[st][end], momkn);
                }
            }

            ll sum = 0;
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if(alive[j] &&alive[k])
                    sum += adj[j][k];
                }
            }
            ans.push_back(sum);
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
