class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size(), res = n, i;
        for(i = n-1; i >= 0 && num[i] != '0'; i--);
        if(i >= 0) res = min(n-1, check(num, i));
        for(i = n-1; i >= 0 && num[i] != '5'; i--);
        return min(res, check(num, i));
    }
    
private:
    int check(string num, int i) {
        for(int j = i-1; j >= 0; j--) {
            int tmp = ((num[j] - '0') * 10) + (num[i] - '0');
            if(tmp % 25 == 0) return num.size() - j - 2;
        }
        
        return num.size();
    }
};