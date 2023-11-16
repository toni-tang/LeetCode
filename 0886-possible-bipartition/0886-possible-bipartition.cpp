class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        const int RED = 1, WHITE = 0, BLUE = -1;
        vector<vector<int>> adj(n + 1, vector<int>());
        
        for(auto& relation : dislikes) {
            adj[relation[0]].emplace_back(relation[1]);
            adj[relation[1]].emplace_back(relation[0]);
        }
        
        queue<int> q;
        vector<int> color(n + 1, 0);
        vector<int> visited(n + 1, 0);
        
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                color[i] = RED;
                q.push(i);
            }
            
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                
                if(visited[curr]) continue;
                visited[curr] = 1;
                
                for(auto& neighbor : adj[curr]) {
                    if(color[curr] == color[neighbor]) return false;
                    
                    color[neighbor] = (color[curr] == RED) ? BLUE : RED;
                    q.push(neighbor);
                }
            }
        }
        
        return true;
    }
};