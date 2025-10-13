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
        int n;
        string s;
        cin >> n >> s;
        int root = sqrt(n);
        if (root * root != n) {
            cout << "No\n";
        }
        else {
            vector<vector<char>>v(root, vector<char>(root));
            int idx = 0;
            for (int i = 0; i < root; i++) {
                for (int j = 0; j < root; j++) {
                    v[i][j] = s[idx];
                    idx++;
                }
            }
            int flag = 0;
            for (int i = 0; i < root; i++) {
                for (int j = 0; j < root; j++) {
                    if (i == 0 || i == root - 1 || j == 0 || j == root - 1) {
                        if (v[i][j] != '1')
                            flag = 1;
                    }
                    else {
                        if (v[i][j] != '0')
                            flag = 1;
                    }
                  
                }
            }
            if (flag) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}
