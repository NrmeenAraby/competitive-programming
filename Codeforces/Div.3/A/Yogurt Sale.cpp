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
        int n,a,b;
        cin >> n>>a>>b;
        int ans = 0;
        if (2 * a > b) {
            int pair = n / 2, one = n - (pair * 2);
            ans = pair * b;
            ans += one * a;
        }
        else {
            ans = n * a;
        }
        cout << ans << "\n";
     

    }
    return 0;
}
