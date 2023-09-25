class Solution {
public:
    int numSquares(int n) {
        int res = INT_MAX;
        int square = round((float)n/2);
        dfs(n, square, 0, res);
        return res;
    }

    void dfs(int n, int square, int count, int& res) {
        if(n < 0 || square == 0 || count > res) return;
        if(n == 0) {
            res = min(res, count);
        }
        
        if(pow(square, 2) <= n) {
            dfs(n - pow(square, 2), square, count+1, res);
        }
        
        dfs(n, square-1, count, res);
    }
};