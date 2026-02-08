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
#define ll  long long
using namespace std;
const int MAX = 1e9;
const long double err = 1e-12;
const long long MOD = 1e9 + 7;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b && a < c) {
            cout << "First\n";
        }
        else if (b < a && b < c) {
            cout << "Second\n";
        }
        else {
            cout << "Third\n";
        }
    }
    return 0;
}
