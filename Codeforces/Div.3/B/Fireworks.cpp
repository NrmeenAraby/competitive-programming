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
#include<string>
#include <functional>
#include <iomanip>
using namespace std;
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;

#define ll  long long

int main() {
    // at some time(the lcm(a,b) minute ) both of them will fire at the same moment, so at least there is 2 will be together
    // and take in count the number of firewoeks that will meet within the m minutes from each setup
    int t;
    cin >> t;
    //cout << fixed << setprecision(10);
    while (t--) {
        ll  a, b, m;
        cin >> a >> b >> m;
        ll ans = (m / a) + (m / b) + 2;
        cout << ans << "\n";
    }

    return 0;
}
