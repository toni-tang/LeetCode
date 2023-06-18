class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = piles[0];
        
        for(int i = 0; i < piles.size(); i++) 
        {
            maxPile = max(piles[i], maxPile);
        }
        
        int res = maxPile;
        int L = 1;
        while(L <= maxPile) 
        {
            int mid = L + (maxPile - L) / 2;;
            int long hours = 0;
            for(int i = 0; i < piles.size(); i++) 
            {
                hours += ceil((double) piles[i]/mid);
            }
            
            if(hours <= h) {
                res = min(mid, res);
                maxPile = mid-1;
            }
            else
            {
                L = mid + 1;
            }
        }
        
        
        return res;
    }
};