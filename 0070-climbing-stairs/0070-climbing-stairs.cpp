class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) return n;
        
        int a = 1, b = 2, c = 0;
        n -= 2;
        while(n--) {
            c = a + b;
            a = b;
            b = c;
        }
        //1, 2, 3, 5, 8
        return c;
    }
};