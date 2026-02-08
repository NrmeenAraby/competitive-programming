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
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;
int main() {
  /*
   -Start by making all X digits equal to 1 >> this uses 2X sticks >> so Remaining sticks = Y − 2X
   -Each digit can absorb up to 5 extra sticks (to become an 8) >> So as long as 0 ≤ (Y − 2X) ≤ 5X, which simplifies to: 2X ≤ Y ≤ 7X
          We can distribute the extra sticks across digits and turn some 1s into 7, 4, 5, 6, or 8.
  */
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        string d;
        cin >> n >> d;
        vector<int>v = {6,2,5,5,4,5,6,3,7,6};
        int tot = 0;
        for (int i = 0; i < n; i++) {
            tot += v[d[i] - '0'];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int dig = 9; dig >= 0; dig--) {
                int remChars = n - 1 - i;
                int remSticks = tot - v[dig];
                if (remSticks <= 7 * remChars && remSticks >= 2 * remChars) {
                    ans.push_back(dig);
                    tot -= v[dig];
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
