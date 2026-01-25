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
        int n, s, x;
        cin >> n >> s >> x;
        int sum = 0,y;

        for (int i = 0; i < n; i++) {
            cin >> y;
            sum += y;
        }
        if (sum > s) {
            cout << "No\n";
        }
        else {
            int rem = s - sum;
            if (rem % x == 0)
            {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
    return 0;
}
