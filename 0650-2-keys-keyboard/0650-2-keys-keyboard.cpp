class Solution {
public:
    int minSteps(int n) {
        int res = INT_MAX;
        dfs(n, 1, res, 0, 0);
        return res;
    }
    void dfs(int n, int len, int& res, int copy, int moves) {
        if(len > n) return;
        if(n == len) {
            res = min(res, moves);
        }
        
        if(copy != 0) {
            dfs(n, len+copy, res, copy, moves+1);   
        }
        if(len != copy) {
            dfs(n, len, res, len, moves+1);
        }
    }
};