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
    /* it is just about that elements in the middle cancels each other, so it is about 1st and last element
      >>EX: a1 ,a2, a3, a4
      (a2-a1)+(a3-a2)+(a4-a3) = -a1+a4
    */
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 1; i < n - 1; i++) {
            if (v[i] == -1)
                v[i] = 0;
        }
        if (v[0] == -1 && v[n - 1] == -1) {
            v[0] = 0;
            v[n - 1] = 0;
        }
        else if (v[0] == -1)
            v[0] = v[n - 1];
        else if (v[n - 1] == -1)
            v[n - 1] = v[0];

        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans += (v[i] - v[i - 1]);
        }
        if (ans < 0)ans *= -1;
        cout << ans << "\n";
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";

    }
    return 0;
}
