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
const int MAX = 2e5+5;
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int x, y;
        int s = 2000, end = 2000; // as constrains till 1000 only
        for (int i = 0; i < 4; i++) {
            cin >> x >> y;
            if (s == 2000) {
                s = x;
            }
            else if (x != s) {
                end = x;
            }
        }
        cout << abs(end - s) * abs(end - s) << endl;
    }
    return 0;
}
