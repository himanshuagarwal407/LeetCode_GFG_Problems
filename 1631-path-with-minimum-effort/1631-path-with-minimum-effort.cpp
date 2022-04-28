class Solution {
private:
    bool valid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    int dijkstra(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        vector<int> dir = {0, 1, 0, -1, 0};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, 0, 0});
        
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int d = v[0];
            int x = v[1];
            int y = v[2];
            if(dist[x][y] < d) continue;
            if(x == n - 1 && y == m - 1) return d; // Optimization
            
            for(int i=0; i<4; i++) {
                int nx = dir[i] + x;
                int ny = dir[i + 1] + y;
                if(!valid(nx, ny, n, m)) continue;
                
                if(dist[nx][ny] > max(d, abs(heights[x][y] - heights[nx][ny]))) {
                    dist[nx][ny] = max(d, abs(heights[x][y] - heights[nx][ny]));
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        }
        // This line won't run (It would be run if the optimization is not applied)
        return dist[n - 1][m - 1] == INT_MAX ? 0 : dist[n - 1][m - 1];
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijkstra(heights);
    }
};