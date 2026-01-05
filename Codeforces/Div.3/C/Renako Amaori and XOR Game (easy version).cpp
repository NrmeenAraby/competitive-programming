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
        vector<int>a(n), b(n);
        int ones = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1)
                ones++;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] == 1)
                ones++;
        }
        if (ones % 2 == 0) {
            cout << "Tie\n";
        }
        else {
            int who=0;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i])
                    who = i + 1;
            }
            if (who % 2 == 0) //(even idx) >> mai is the last one who makes swap
            {
                cout << "Mai\n";
            }
            else {   //(odd idx) >> Ajisai is the last one who makes swap
                cout << "Ajisai\n";
            }
        }
    }
    return 0;
}
