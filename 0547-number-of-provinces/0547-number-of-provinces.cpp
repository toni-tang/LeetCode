class Solution {
public:
    void dfs(vector<int>& visited, int i, vector<vector<int>>& isConnected) {
        for(int j = 0; j < isConnected.size(); j++) {
            if(visited[j] == 0 && isConnected[i][j] == 1 && i != j) {
                visited[j] = 1;
                dfs(visited, j, isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                visited[i] = 1;
                dfs(visited, i, isConnected);
                res++;
            }
        }

        return res;
    }
};