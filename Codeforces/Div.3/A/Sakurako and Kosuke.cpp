#include <iostream>
#include <vector>
#include<deque>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;
int main() {
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;   
      if (n % 2 == 0) {
            cout << "Sakurako\n";
        }
        else {
            cout << "Kosuke\n";
        }
    }
    return 0;
}
