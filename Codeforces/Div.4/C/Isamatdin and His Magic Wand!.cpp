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

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n);
        int even=0, odd=0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] % 2 == 0)
                even = 1;
            else
                odd = 1;
        }
        if (even && odd)
            sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
   
    return 0;
}
