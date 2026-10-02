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
const int MAX = 2e5 + 5;
const int INF =1e9;
const int MOD = 1e9 + 7;

int main() {
    // the real problem is about the element in array a that is greater than b. in this case, to decrese this element, u must increase the element before 
    // if element in a less than b, u can easily increase this element (l=r, l-l=0 >> even, so +1)
    // u will never need to take a segemnt of more than 2 elements 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long>a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = n - 1; i > 0; i--) {
            if (a[i] > b[i])
                a[i - 1] += (a[i] - b[i]);
        }
        if (a[0] > b[0])
            cout << "no\n";
        else
            cout << "yes\n";
    }
    return 0;
}
