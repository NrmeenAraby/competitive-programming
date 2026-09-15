class Solution {
public:
    vector<string>ans;
    int n;
    void solve(int opn, int cls, string curr) {
        if (opn == n && cls == n) {
            ans.push_back(curr);
            return;
        }

        if (opn < n) {
            solve(opn + 1, cls, curr+"(");
        }

        if (cls < opn) {
            solve(opn, cls + 1, curr+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        solve(0, 0,"");
        return ans;
    }
};
