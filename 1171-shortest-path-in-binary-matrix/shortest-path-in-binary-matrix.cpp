class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<pair<int, int>> direction = {
            {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}
        };

        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>>pq;

        pq.push({1, {0,0}});

        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        dist[0][0] = 1;

        while(!pq.empty()){
            int d = pq.top().first;
            auto position = pq.top().second;
            int x = position.first;
            int y = position.second;

            pq.pop();

            if(x == n-1 && y == n-1) return d;

            if(d > dist[x][y]) continue;

            for(auto [dx, dy] : direction){
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0){
                    if(d + 1 < dist[nx][ny]){
                        dist[nx][ny] = d + 1;
                        pq.push({d+1, {nx,ny}});
                    }
                }
            }
        }

        return -1;
    }
};