class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        int copy = n;
        int places = 0;
       
        while(copy)
        {
            copy /= 10;
            places++;
        }   
        
        cout << places << endl;
        
        if(places != 1)
        {
            places = (places % 2 == 0) ? -1 : 1; 
        }
    
        while(n) {
            cout << ((n % 10) * places) << endl;
            sum = sum + ((n % 10) * places);
            places = (places == 1) ? -1 : 1;
            n /= 10;
        }
            
        return sum;
    }
};