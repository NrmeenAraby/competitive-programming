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
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int maxSoFar = 0;
        vector<int>dp(n);
        map<int, pair<int, deque<int>>>mp;
    
        for (int i = 0; i < n; i++) {
            int tmp = a[i]; 
            mp[tmp].first++;
            mp[tmp].second.push_back(maxSoFar);
           
            if (mp[tmp].first ==tmp) {
                dp[i] = tmp + mp[tmp].second.front();
                maxSoFar = max(maxSoFar, dp[i]);
                mp[tmp].first --;
                mp[tmp].second.pop_front();
            }    
        }
        auto it = max_element(dp.begin(), dp.end());
        int ans = *it;
        cout << ans << "\n";
    }
   
    return 0;
}
