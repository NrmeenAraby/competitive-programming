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
#include <numeric>
#include<queue>
#include<array>
using namespace std;
const long long MAX = 1e18;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string p, s;
        cin >> p >> s;
        map<int, pair<int,char>>mp;
        int cntrP = 1,mpCntr=0;
        if (p.size() == 1) {
            mpCntr++;
            mp[mpCntr] = { 1,p[0] };
        }
        else {
            for (int i = 1; i < p.size(); i++) {
               
                if (p[i] == p[i - 1]) {
                    cntrP++;
                }
                else {
                    mpCntr++;
                    mp[mpCntr] = { cntrP,p[i - 1] };
                    cntrP =1;
                  
                }
            }
                mpCntr++;
                mp[mpCntr] = { cntrP,p[p.size() - 1] };
            
        }

        if (s.size() < p.size()) {
            cout << "No\n";
        }
        else if (s.size() == 1) {
            if (p[0] == s[0])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else {
            int flag = 0, cntrS = 1, mpCheck = 0;
            for (int i = 1; i < s.size(); i++) {
                if (s[i] == s[i - 1]) {
                    cntrS++;
                }
                else {
                    mpCheck++;
                    if (mp.find(mpCheck) == mp.end() || cntrS< mp[mpCheck].first || cntrS >(2 * mp[mpCheck].first) || s[i - 1] != mp[mpCheck].second) {
                        flag = 1;
                    }
                    cntrS = 1;
                   
                }
            }
            if (!flag ) {
                mpCheck++;
                if (mp.find(mpCheck) == mp.end() || cntrS< mp[mpCheck].first || cntrS >(2 * mp[mpCheck].first) || s[s.size() - 1] != mp[mpCheck].second) {
                    flag = 1;
                }
            }
            if (flag || mpCheck < mpCntr) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}
