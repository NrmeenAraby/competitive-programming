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
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int sum = 0;
        ll x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (i % (k + 1) == 0) {  // starting from first pile, every k+1 pile contribues with odd moves for each stone in this pile 
                if (x % 2 && sum == 1) // chacking on the number of stones on the pile and consider the stored parity
                    sum = 0;
                else if (x % 2 && sum == 0)
                    sum = 1;
            }
        }

        if (sum)
            cout << "Alice\n";
        else
            cout << "Bob\n";

    }
    return 0;
}
