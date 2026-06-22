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
const int MAX = 2e3 + 5;
int dp[MAX][MAX];
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int h, w, xa, ya, xb, yb;
        cin >> h >> w >> xa >> ya >> xb >> yb;
        if (xa >= xb) {
            cout << "Draw\n";
        }
        else{
            int diff = abs(xa - xb);
            if (diff % 2==1) { 
                if (ya == yb) {
                    cout << "Alice\n";
                }
                else {
                    int moves = diff/2;
                    int movesA = moves+1;
                    int movesB = moves;
                    int finalA = ya;
                    int finalB = yb;
                    if (yb > ya) {
                        finalA += movesA;
                        finalB += movesB;
                        if (finalA == finalB || finalA >= w) {
                            cout << "Alice\n";
                        }
                        else {
                            cout << "Draw\n";

                        }
                    }
                    else if(yb<ya){
                        finalA -= movesA;
                        finalB -= movesB;
                        if (finalA == finalB || finalA<=1) {
                            cout << "Alice\n";
                        }
                        else {
                            cout << "Draw\n";

                        }
                    }
                   
                }
                
            }
            else {
                if (ya == yb) {
                    cout << "Bob\n";
                }
                else {
                    int moves = diff/2;
                    int finalA = ya;
                    int finalB = yb;
                    if (yb > ya) {
                        finalA -= moves;
                        finalB -= moves;
                        if (finalA == finalB || finalB <= 1) {
                            cout << "Bob\n";
                        }
                        else {
                            cout << "Draw\n";
                        }
                    }
                    else if (yb < ya) {
                        finalA += moves;
                        finalB += moves;
                        if (finalA == finalB || finalB>=w ) {
                            cout << "Bob\n";
                        }
                        else {
                            cout << "Draw\n";

                        }
                    }

                }
            }

        }
    }
    return 0;
}
