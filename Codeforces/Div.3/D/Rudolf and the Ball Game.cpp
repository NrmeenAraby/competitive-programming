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
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        vector<pair<int, char>>q(m);
        int r;
        char ch;
        for (int i = 0; i < m; i++) {
            cin >> r >> ch;
            q[i] = { r,ch };
        }
        set<int>prev, nxt,tmp;
        prev.insert(x);
        for (int i = 0; i < m; i++) {
            for (int curr : prev) {
                ch = q[i].second;
                int node, node2 = -1, dis = q[i].first;
                if (ch == '0') {
                    node = curr + dis;
                }
                else if (ch == '1') {
                    int rr = n - dis;
                    node = curr + rr;
                }
                else {
                    node = curr + dis;
                    int rr = n - dis;
                    node2 = curr + rr;
                }
                if (node > n) {
                    node = node % n;
                }
                nxt.insert(node);
                if (node2 != -1) {
                    if (node2 > n)
                        node2 %= n;
                    nxt.insert(node2);
                }
            }
            prev = nxt;
            nxt.clear();
          //  prev = move(nxt);
        }
        cout << prev.size() << "\n";
        for (int z : prev) {
            cout << z << " ";
        }
        cout << endl;
    }
    return 0;
}
