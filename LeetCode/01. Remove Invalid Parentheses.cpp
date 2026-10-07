class Solution {
    set<string>lst;
    string s;
    int mx = 0;
    void solve(int idx, int opn, int cls,int balance, string curr) {

        if (idx == s.size()) {
            if (opn==0 && cls==0 && balance==0) {
                lst.insert(curr);
            }
            return;
        }

        char c = s[idx];

        if (c == '(') {

            //remove
            if(opn>0)
             solve(idx + 1, opn - 1, cls, balance,curr);

            //keep
            solve(idx + 1, opn, cls, balance+1,curr+c);
        }
        else if (c == ')') {
            //remove
            if(cls>0)
                solve(idx + 1, opn, cls - 1, balance,curr);

            //u keep ")" just in case there is "("
            if(balance>0)
              solve(idx + 1, opn, cls, balance-1,curr+c);
        }
        else {
            solve(idx + 1, opn, cls,balance, curr + c);
        }

    }
public:
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        int opn = 0, cls = 0; //need to be removed
        for (char c : s) {
            if (c == '(')
                opn++;
            else if(c==')') {
                if (opn > 0)
                    opn--;
                else
                    cls++;
            }
        }
        solve(0,opn,cls,0,"");
        vector<string>ans;
        for (auto st : lst) {
            ans.push_back(st);
        }
        return ans;
    }
};
