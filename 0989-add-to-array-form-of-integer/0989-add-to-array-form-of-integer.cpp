class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        vector<int> res;
        
        for(int i = num.size()-1; i >= 0; i--) {
            int temp = k%10 + num[i] + carry;
            k /= 10;
            res.push_back(temp % 10);
            carry = temp / 10;
        }
        
        while(k)
        {
            int temp = k%10 + carry;
            res.push_back(temp % 10);
            k /= 10;
            carry = temp / 10;
        }
        
        if(carry > 0) res.push_back(carry);
        reverse(res.begin(), res.end());
            
        return res;
    }
};