class Solution {
public:
    int minOperations(vector<int>& A) {
        unordered_map<int, int> count;
        
        // Count frequencies of elements
        for (int a : A) {
            ++count[a];
        }
        
        int res = 0;
        // For each loop extracting the map
        for (auto& [_, c] : count) {
            if (c == 1) return -1; // Edge case for 1;
            res += (c + 2) / 3; // Always need k+1 operations for elements not fully divisble by 3; For remainders 1 & 2;
        }
        return res;
    }
};