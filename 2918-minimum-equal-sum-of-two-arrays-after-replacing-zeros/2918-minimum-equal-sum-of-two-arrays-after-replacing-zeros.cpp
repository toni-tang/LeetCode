class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeroOne = 0, zeroTwo = 0;
        long long sumOne = 0, sumTwo = 0;
        
        for(auto& n : nums1) {
            if(n == 0) zeroOne++;
            sumOne += n;
        }
        
        for(auto& n : nums2) {
            if(n == 0) zeroTwo++;
            sumTwo += n;
        }
        
        if(zeroOne == 0 && sumOne < sumTwo + zeroTwo) return -1;
        if(zeroTwo == 0 && sumTwo < sumOne + zeroOne) return -1;
        
        return max(sumOne + zeroOne, sumTwo + zeroTwo);
    }
};