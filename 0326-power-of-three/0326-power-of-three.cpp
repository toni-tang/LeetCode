class Solution {
public:
    bool isPowerOfThree(int n) {
        long long x = 1;
        
        while(x < n)
        {
            x = x*3;    
        }
        
        return x == n;
    }
};