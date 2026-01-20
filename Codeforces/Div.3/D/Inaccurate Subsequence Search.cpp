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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int>a(n), b(m);
        map<int, int>mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            mp[b[i]] ++;
        }
        int i = 0, j = 0,ans=0,cntr=0;
        map<int,int>check;
        while (i < n - m+1) {
            while (j < n && j-i<m) {
                if (mp[a[j]] >= 1) {
                    check[a[j]]++;
                    if (check[a[j]] <= mp[a[j]])
                        cntr++;
                }
                j++;
            }
            if (cntr >= k) {
                ans++;
            }
            if (check.find(a[i])!=check.end() ) {
                check[a[i]]--; 
                if (check[a[i]] < mp[a[i]])
                    cntr--;
              /*  if (check[a[i]] == 0) {
                    check.erase(a[i]);
                }*/
            }
           
            i++;
        }
        cout << ans << "\n";

    }
    return 0;
}
