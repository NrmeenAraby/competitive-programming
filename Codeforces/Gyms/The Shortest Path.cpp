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
int n;
vector<pair<pair<int, int>, long long>> edges;
vector<long long>dist;
bool relax() {
    bool fnd = false;
    for (auto& e : edges) {
        int u = e.first.first;
        int v = e.first.second;
        long long w = e.second;
        if (dist[u] != MAX && dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
                fnd = true;
            }
        }
    
    return fnd;
}
bool bellman(int src) {
    dist.assign(n+2, MAX);
    dist[src] = 0;
    for (int i = 0; i < n; i++) {  //n and not n-1 bec here we use super source node (added a faked node)
        relax();
    }
    return relax();
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int  m;
        cin >> n >> m;
        edges.clear();
        int u, v, c;
        int negW = 0;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> c;
            edges.push_back({ {u, v}, c });
            if (c < 0)
                negW = 1;
        }
        if (negW == 0) { //34an el dist bta3t el fake node = 0, so it will be always the smallest dist which is wrong, so we must handle if all edges +ve 
            long long mn = MAX;
            for (auto& e : edges) {
                int u = e.first.first;
                int v = e.first.second;
                long long w = e.second;
                mn = min(mn, w);
            }
            cout << mn << "\n";
        }
        else {
            //add the fake node
            for (int i = 1; i <= n; i++) {
                edges.push_back({ {n + 1, i}, 0 });
            }
            if (bellman(n + 1)) //start from this super source fake node
            {
                cout << "-inf\n";
            }
            else {
                long long mn = MAX;
                for (int i = 1; i <= n; i++) {
                    mn = min(mn, dist[i]);
                }
                cout << mn << "\n";
            }
        }
    }
    return 0;
}
