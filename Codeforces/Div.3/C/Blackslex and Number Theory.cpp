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
    //all the array will be zero. OR all the array will be the min num in the array>>so larger k.
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int mn = v[0], mn2 = v[1];
        int possible = mn2 - mn;   //34an ay 7aga akbr mn el "mn" kda kda hatdeny el "mn", fa kda tany as8r raqm howa elly hay7dd eh akbr K momkn awslha fa lw kant "mn2 - mn" akbr mn el "mn" so this is the answer w kda kda rest of the array akbr so they can be handled with "mn2 - mn" or larger
        if (mn>=possible) {
            cout << mn << "\n"; //all the array will be zero
        }
        else {
            cout <<possible << "\n"; // all the array will be the min num in the array 
        }
     

    }
    return 0;
}
