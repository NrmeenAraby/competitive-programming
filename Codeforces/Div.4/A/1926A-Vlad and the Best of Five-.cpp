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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cntrA=0;
        for (int i = 0; i < 5; i++) {
            if (s[i] == 'A')
                cntrA++;
        }
        if (cntrA >= 3)
            cout << "A\n";
        else
            cout << "B\n";
    }
    
    return 0;
}
