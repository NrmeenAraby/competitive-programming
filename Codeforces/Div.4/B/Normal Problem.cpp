#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
 
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'p')
                s[i] = 'q';
            else if (s[i] == 'q')
                s[i] = 'p';
        }
        cout << s << "\n";
    }
    return 0;
}
