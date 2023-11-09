class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int res = 0;
        while(k && numOnes) {
            k--;
            numOnes--;
            res++;
        }
        while(k && numZeros){
            k--;
            numZeros--;
        }
        while(k && numNegOnes) {
            k--;
            numNegOnes--;
            res--;
        }
        
        return res;
    }
};