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
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,m,h;
        cin >> n>>m>>h;
        vector<int>a(n+1),aa(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            aa[i] = a[i];
        }
        int b, c;
        vector<pair<int, int>>op(m+1);
        for (int i = 1; i <= m;i++) {
            cin >> b >> c;
            op[i] = { b,c };
        }
        map<int, int>lastUsedFlag;
        int flag = -1;

        for (int i = 1; i <= m; i++) {
            int idx = op[i].first, c = op[i].second;
            if (flag > lastUsedFlag[idx]) {
                aa[idx] = a[idx];
                lastUsedFlag[idx] = flag;
            }
            if (aa[idx] + c > h) {
                flag = i;
            }
            else {
                aa[idx] += c;
            }
        }
        for (auto it : lastUsedFlag) {
            if (flag > it.second) {
                aa[it.first] = a[it.first];
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << aa[i] << " ";
        }
        cout << endl;
        
    }
    return 0;
}
