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
        long long n;
        cin >> n;
        long long x, mx = 0;
        for (long long i = 0; i < n; i++) {
            cin >> x;
            mx = max(mx, x);
        }
        cout << mx * n << "\n";
    }
    return 0;
}
