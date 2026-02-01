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

    int t;
    cin >> t;
    while (t--) {
        double n;
        cin >> n;
        string s;
        cin >> s;
        vector<int>zeros(n + 1), ones(n + 1);
        if (s[0] == '0')
            zeros[1] = 1;
        for (int i = 2; i <= n; i++) {

            zeros[i] = zeros[i - 1];
            if (s[i - 1] == '0')
                zeros[i]++;
        }
        if (s[n - 1] == '1')
            ones[n] = 1;
        for (int i = n - 1; i >= 1; i--) {
            ones[i] = ones[i + 1];
            if (s[i - 1] == '1')
                ones[i]++;
        }
        int possible = -1, tohalf = -1;
        double half = n  / 2.0;
        for (int i = 1; i < n; i++) {
            int zHalf = (i + 1) / 2,oHalf=(n-i+1)/2;
            if (zeros[i] >= zHalf && ones[i+1] >= oHalf) {

                if (abs(half - i) < tohalf || possible == -1)
                {
                    possible = i;
                    tohalf = abs(half - i);
                }

            }
        }
        if (possible == -1)
        {
            if (zeros[n] > ones[1])
                possible = n;
            else
                possible = 0;
        }
        cout << possible << "\n";
    }

    return 0;
}
