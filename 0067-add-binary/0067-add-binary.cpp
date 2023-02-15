class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1 , j = b.length()-1;
        string res = "";
        
        int carry = 0 , first = 0, second = 0;; 
        while(i >= 0 || j >= 0) {
            if(i < 0) {
                first = 0;
            }
            else {
                first = (int)a[i] - 48;
            }
            
            if(j < 0) {
                second = 0;
            }
            else {
                second = (int)b[j] - 48;
            }
            
            int sum = first + second + carry;
            
            if(sum == 3) 
            {
                carry = 1;
                res.push_back('1');
            }
            else if(sum == 2)
            {
                carry = 1;
                res.push_back('0');
            }
            else if(sum == 1)
            {
                carry = 0;
                res.push_back('1');
            }
            else {
                carry = 0;
                res.push_back('0');
            }
            
            i--;
            j--;
        }
        
        if(carry == 1)
        {
            res.push_back('1');
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};