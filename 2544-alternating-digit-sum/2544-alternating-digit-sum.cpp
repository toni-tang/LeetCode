class Solution {
public:
    int alternateDigitSum(int n) {
        int copy = n;
        int sum = 0;
        int places = 0;
       
        while(copy)
        {
            copy /= 10;
            places++;
        }   
        
        places = (places % 2 == 0) ? -1 : 1; 
    
        while(n) {
            cout << ((n % 10) * places) << endl;
            sum = sum + ((n % 10) * places);
            places = (places == 1) ? -1 : 1;
            n /= 10;
        }
            
        return sum;
    }
};