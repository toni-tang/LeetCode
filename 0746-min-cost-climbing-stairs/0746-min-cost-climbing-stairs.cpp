class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0) return 0;
        if(n == 1) return cost[0];
        if(n == 2) return min(cost[0], cost[1]);

        int a = cost[0], b = cost[1], c = 0;
        for(int i = 2; i < cost.size(); i++) {
            c = min(a, b) + cost[i];   
            a = b;
            b = c;
            
        }
        
        return min(a, b);
    }
};