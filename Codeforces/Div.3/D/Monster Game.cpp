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
const int MAX = 1e9;
int dx[] = { 1,0,0 };
int dy[] = { 0,1,-1 };
/*map<pair<int, int>, int>grid;
void bfs(int sx, int sy) {
    queue<pair<int, int>>q;
    q.push({ sx,sy });
    while (!q.empty()) {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i],ny=y+dy[i];
            if (nx >= n || nx < 0 || ny >= n || ny < 0 || grid.find({nx,ny}) != grid.end()) continue;
            grid[{nx, ny}]++;
            q.push({ nx,ny });
        }
    }
}*/ 
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long>a(n),b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end(), greater<>());
        for (int i = 1; i < n; i++) {
            b[i] += b[i - 1];
        }
        long long mx = 0;
        for (int lvl = 0; lvl < n; lvl++) {
            long long neededSwords = b[lvl];
            if (neededSwords <= n) {
                long long lvls = lvl + 1;
                long long strength = a[neededSwords - 1];
                mx = max(mx, strength * lvls);
            }
            else
                break;
        }
        cout << mx<<"\n";
    }
    return 0;
}
