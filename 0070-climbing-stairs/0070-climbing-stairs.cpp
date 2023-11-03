class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        n -= 2;
        
        int a = 1, b = 2, c;
        while(n) {
            c = a + b;
            a = b;
            b = c;
            n--;
        }
        
        return c;
    }
};