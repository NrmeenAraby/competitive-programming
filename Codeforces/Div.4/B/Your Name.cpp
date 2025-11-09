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
        string s, st;
        cin >> s >> st;
        map<char, int>mps,mpst;
        for (int i = 0; i < s.size(); i++) {
            mps[s[i]] += 1;
            mpst[st[i]] += 1;
        }
        int flag = 0;
        for (int i = 0; i < st.size(); i++) {
            if (mpst[st[i]] !=mps[st[i]]) {
                flag = 1;
            }
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
   
    return 0;
}
