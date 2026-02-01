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
    // what is the last l ?, knowing last l is enough to guarantee that u can find x 
    // so one operation is always enough
    //as the conditon is pm<=x, so replacing l with x wont affect the rest of the binary search operations and we need to replace x to the last l so this x always the last element idx put in the l 
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int>p(n);
        int j = -1;
        for (int i =0 ; i < n; i++) {
            cin >> p[i];
            if (p[i] == x) {
                j = i;
            }
        }
        int l = 0, r = n ;
        while (r - l != 1) {
            int md = (r + l) / 2;
            if (p[md] <= x) {
                l = md;
            }
            else {
                r = md;
            }
        }


        cout << 1 << "\n";
        cout << l+1 << " " << j+1 << "\n";

    }

    return 0;
}
