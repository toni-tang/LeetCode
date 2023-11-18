class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int RED = 1, WHITE = 0, BLUE = -1;
        
        int n = graph.size();

        queue<int> q;
        vector<int> color(n, 0);
        vector<int> visited(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                color[i] = RED;
                q.push(i);
            }
            
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                
                if(visited[curr]) continue;
                visited[curr] = 1;
                
                for(auto& neighbor : graph[curr]) {
                    if(color[curr] == color[neighbor]) return false;
                    
                    color[neighbor] = (color[curr] == RED) ? BLUE : RED;
                    q.push(neighbor);
                }
            }
        }
        
        return true;
    }
};