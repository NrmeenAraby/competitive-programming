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
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long>a(n);
        vector<bool>here(n + 1, false);
        vector<int>dp(n + 1, MAX);
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            here[a[i]] = true;
            dp[a[i]] = 1; //direct operation(the number is already here)
        }

        for (int x = 2; x <= n; x++) {
            if (here[x]) {
                for (int y = 2; x*y <= n; y++) {
                    if (dp[y] != MAX) {
                        dp[x * y] = min(dp[x * y], dp[y] + 1);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dp[i] == MAX) {
                cout << -1 ;
            }
            else {
                cout << dp[i];
            }
            if (i < n) cout << " ";
        }
        cout << "\n";


    }
    return 0;
}
