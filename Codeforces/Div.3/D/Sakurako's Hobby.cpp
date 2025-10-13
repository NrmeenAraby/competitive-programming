#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cmath>
using namespace std;
int cntr;
vector<vector<int>>adj;
vector<int>color;
vector<int>vis;
vector<int>ans;
vector<int>temp;
void dfs(int src){
    if (color[src] == 0)
        cntr++;
    vis[src] = 1;
    temp.push_back(src);
    for (auto &neig : adj[src]) {
        if (!vis[neig]) {
            dfs(neig);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        adj.assign(n + 1, {});
        vis.assign(n + 1, 0);
        color.assign(n + 1,0);
        ans.assign(n + 1,0);
        vector<int>nodes(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> nodes[i];
            adj[i].push_back(nodes[i]);

        }
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                color[nodes[i + 1]] = 0;
            }
            else {
                color[nodes[i + 1]] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i])
            {
                cntr = 0;
                temp.clear();
                dfs(i);
                for (auto node :temp) {
                    ans[node] = cntr;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
