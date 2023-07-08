class Solution {
public:
    int rob(vector<int>& nums) {
        // UNDERSTAND 
        // Objective: Max amount of money to rob
        // Condition: Can't rob adjacent houses,
        // Questions: Is the array ever empty?, Do houses have negative money??
        
        // MATCH
        // Dynamic Programming - Fibonacci Sequence Pattern, 1D
        
        // PLAN
        // Loop through array
        // Compare sum[i] = max(arr[i-2] + a[i], arr[i-1]);
        
        
        // IMPLEMENT
        int A = 0, B = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = max(nums[i] + A, B);
            A = B;
            B = temp;
        }
        
        return B;
        
        // REVIEW
        // EVALUATE 
    }
};