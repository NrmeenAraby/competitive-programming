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
        int n;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long long diff=0;
        for (int i = 1; i < n; i++) {
             diff += abs(v[i] - v[i - 1]);  
        }
        long long sol = diff,tmp=0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                tmp=diff- abs(v[i] - v[i + 1]);
            }
            else if (i == n - 1) {
                tmp =diff- abs(v[i] - v[i - 1]);
            }
            else {
                tmp =diff - abs(v[i] - v[i - 1]);
                tmp -= abs(v[i] - v[i + 1]);
                tmp += abs(v[i + 1] - v[i - 1]);
            }
            sol = min(sol, tmp);

        }
        cout << sol << "\n";

    }
    return 0;
}
