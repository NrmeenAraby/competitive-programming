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
using namespace std;
const int MAX = 1e9;
const long double err = 1e-12;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int cntr = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i] && a[j]!=-1) {
                    cntr++;
                    a[j] = -1;
                    
                }
            }
           
        }
        cout << cntr << "\n";
    }
    return 0;
}
