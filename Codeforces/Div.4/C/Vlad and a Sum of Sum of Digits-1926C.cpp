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
    vector<int>mem(2e5+5);
    for (int i = 1; i < 2e5 + 5; i++) {
        int sum = 0;
        int tmp = i;
        while (tmp != 0) {
            sum += (tmp % 10);
            tmp /= 10;
        }
        mem[i] = sum;
        if (i > 1)
            mem[i] += mem[i - 1];
    }
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << mem[n] << "\n";
    }
    
    return 0;
}
