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
#include<string>
#include <functional>
#include <iomanip>
#define ll  long long
using namespace std;
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;

int main() {
    int t = 1;
   // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<ll>>adj(n + 1,vector<ll>(n+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> adj[i][j];
            }
        }
        int k;
        cin >> k;
        int u, v;
        ll c;
        while (k--) {
            cin >> u >> v>>c;
            for (int st = 1; st <= n; st++) {
                for (int end = 1; end <= n; end++) {
                    ll momkn = adj[st][u] + c + adj[v][end];
                    ll wmomkn = adj[st][v] + c + adj[u][end];
                    adj[st][end] = min(adj[st][end], min(momkn, wmomkn));
                }
            }
            ll sum = 0;
            for (auto i : adj) {
                for (auto element : i) {
                    sum += element;
                }
            }
            sum /= 2;   // Each pair of cities should be taken into account in the sum exactly once, and adj[i][j] is  exactly adj[j][i] 
            cout << sum << " ";
        }
        cout << "\n";

    }
    return 0;
}
