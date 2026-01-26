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
        //only count what can be paid, not who pays whom >> ao no need to think about min(max(l,x),max(x,r))
        int n;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int mx = *max_element(v.begin(), v.end());
        long long sum = 0;
        for (int i = 0; i < n-1; i++) {
            sum += max(v[i], v[i + 1]);
        }
        sum += max(v[0], v[n - 1]);
        sum -= mx; //tp avoid overcounting as the maximum element will never be killed 
        cout << sum << "\n";
    }
    return 0;
}
