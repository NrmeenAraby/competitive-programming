#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int valToAdd = 0;
        //int ans = 0;
        while (l <= r) {
            valToAdd++;
            l += valToAdd;
            //ans++;
        }
        cout << valToAdd<< "\n";
    }
    return 0;
}
