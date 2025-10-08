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
        int n,k;
        cin >> n>>k;
        int start = n - k + 1;
        int end = n;
        int oddsTillEnd = (end + 1) / 2;
        int oddsBeforeStart = start / 2;
        int oddsInInterval = oddsTillEnd - oddsBeforeStart;
        if (oddsInInterval % 2 == 0) {  //The sum of even num of odds  is even
            cout << "yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}
