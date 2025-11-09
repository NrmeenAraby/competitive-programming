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
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long>a(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            sum += c[i];
        }
        vector<long long>dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = c[i];
            for (int j = 0; j < i; j++) {
                if (a[j] <= a[i]) {
                    dp[i] = max(dp[i], dp[j] + c[i]);
                }
            }
        }
        long long mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, dp[i]);
        }
        cout << sum - mx << "\n";
        
    }
   
    return 0;
}
