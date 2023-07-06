class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n < 3) return 1;
        
        int a = 0, b = 1;
        while(n--) 
        {
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        
        return a;
    }
};