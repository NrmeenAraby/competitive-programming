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
    // the obvious thing : if there is only one block, we can always end up with one element.
    //otherwise, as long as there are more than 2 blocks (number of transitions + 1) >> they can eat each other so we can end up with one element.
    // so the answer will be 2 elements JUST in the case of exactly 2 blocks so one element from each block will reamin forever. 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int transitions = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1])
                transitions++;
        }
        if (transitions == 1)
            cout << 2 << endl;
        else
            cout << 1 << endl;
      
    }
    return 0;
}
