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
    //x<10^8, so max x length is 8, then y can be (10^ x length) +1
    // so y is just 0s and 1s so y is good
    // x*y also guaranteed to be good, since multiplying by 10^d + 1 basically gives us x * 10^d + x (concatenation of x with itself)
    // so y can be 10^d +1 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        string s = to_string(x);
        int len = s.size();
        int y = pow(10ll, len)+1;
        cout << y << endl;
      
    }
    return 0;
}
