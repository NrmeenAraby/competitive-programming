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
const int MAX = 2e5 + 5;
const int INF =1e9;
const int MOD = 1e9 + 7;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main() {
    //Connected components = positions having the same remainder modulo gcd(x,y).
    //gcd(x,y) is the smallest "step size" you can create by combining jumps of x and y.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n,x,y;
        cin >> n>>x>>y;
        vector<ll>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int g = gcd(x, y);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if ((v[i] - 1) % g != i % g) { //same connected componeent
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
