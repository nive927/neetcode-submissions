class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> cols, posDiag, negDiag;

    void backtrack(int r, vector<string> &curr, int n) {

        if(r == n) {
            ans.push_back(curr);
            return;
        }

        for(int c=0; c<n; c++) {

            if(cols.count(c) || posDiag.count(r+c) || negDiag.count(r-c)) {
                continue;
            }

            cols.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            curr[r][c] = 'Q';
            backtrack(r+1, curr, n);
            cols.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);
            curr[r][c] = '.';

        }

    }

    vector<vector<string>> solveNQueens(int n) {

        // r - +1 every call
        // c - iteration
        // n - stays the same
        // curr - init the board with ...., ...., ...., ... (nXn, n=4 here)
        vector<string> curr(n, string(n, '.')); // INIT is IMPORTANT
        backtrack(0, curr, n);

        return ans;
        
    }
};
