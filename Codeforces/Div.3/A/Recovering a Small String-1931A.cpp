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
    map<int, char>mp;
    char c = 'a';
    for (int i = 1; i <= 26; i++) {
        mp[i] = c;
        c = c + 1;
    }
    while (t--) {
        int n;
        cin >> n;
        int first = 1;
        while (n - first > 52)  //26*2=52
        {
            first++;
        }
        cout << mp[first];
        n -= first;
        int sec = 1;
        while (n - sec > 26) {
            sec++;
        }
        cout << mp[sec];
        n -= sec;
        cout << mp[n];
        cout << endl;
    }
    
    return 0;
}
