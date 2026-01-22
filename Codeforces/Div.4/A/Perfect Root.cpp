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
        for (long long i = 1; i <= n; i++) {
            cout << i*i<< " ";
            
        }
        cout << "\n";
    }
    return 0;
}
