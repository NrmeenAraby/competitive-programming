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
int n;
ll dp[MAX];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        cin >> n ;
        string s, st;
        cin >> s >> st;
        int op01 = 0, op10 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != st[i]) {
                if (s[i] == '0')
                    op01++;
                else
                    op10++;
            }
        }
        cout << max(op01, op10)<<endl;
    }
    return 0;
}
