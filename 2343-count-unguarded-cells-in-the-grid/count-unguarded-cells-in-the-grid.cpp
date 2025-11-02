class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m, vector<int>(n, 0));

        for(auto& g : guards){
            grid[g[0]][g[1]] = 1;
        }

        for(auto& w : walls){
            grid[w[0]][w[1]] = 2;
        }

        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};

        for(auto& g : guards){
            int r = g[0];
            int c = g[1];

            for(int i = 0; i < 4; i++){
                int nr = r + x[i];
                int nc = c + y[i];

                while(0 <= nr && nr < m && 0 <= nc && nc < n){
                    if(grid[nr][nc] == 1 || grid[nr][nc] == 2) break;
                    if(grid[nr][nc] == 0) grid[nr][nc] = 3; 
                    nr += x[i];
                    nc += y[i];
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};