#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MOD = 32768;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int flag = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == s[i + 1])
                flag = 1;
        }
        if (flag)
            cout << 1 << "\n";
        else
            cout << s.size() << "\n";
        
    }
    return 0;
}
 
