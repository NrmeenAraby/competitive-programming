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
        int n;
        cin >> n;
        vector<vector<char>>v(n,vector<char>(n));
        int cntPrev = 0,triangle=0;
        for (int i = 0; i < n; i++) {
            int cntr = 0;
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
                if (v[i][j] == '1')
                    cntr++;
            }
            if (cntPrev == 0)
                cntPrev = cntr;
            else if( cntr!=0 && cntPrev!=cntr){
                triangle = 1;
            }
        }
        if (triangle) {
            cout << "TRIANGLE\n";
        }
        else {
            cout << "SQUARE\n";
        }
    }
    
    return 0;
}
