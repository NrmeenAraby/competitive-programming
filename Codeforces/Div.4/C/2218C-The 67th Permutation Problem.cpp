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

int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(3*n,-1);
        int x = 1;
        for (int i = 0; i < 3 * n; i += 3) {
            a[i] = x++;
        }
        for (int i = 1; i < 3 * n; i++) {
            if (a[i] == -1) {
                a[i] = x++;
            }
        }
        for (int i = 0; i < 3 * n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
