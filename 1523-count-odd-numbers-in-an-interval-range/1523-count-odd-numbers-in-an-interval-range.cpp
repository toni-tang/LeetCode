class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2 == 0 && high%2 == 0) return (high - low)/2;
        
        int count = 0;
        for(int i = low; i <= high; i++) {
            if(i%2 == 1) count++;
        }
        
        return count;
    }
};