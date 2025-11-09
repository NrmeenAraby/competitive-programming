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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == b && a == c && a == d) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
      
        cout << endl;
    }
   
    return 0;
}
