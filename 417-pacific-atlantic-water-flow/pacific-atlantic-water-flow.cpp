class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pVisited(row, vector<bool>(col, false));
        vector<vector<bool>> aVisited(row, vector<bool>(col, false));

        queue<pair<int, int>> qPacific;
        queue<pair<int, int>> qAtlantic;

        // Pacific: top row + left column
        for (int i = 0; i < row; i++) {
            if (!pVisited[i][0]) {
                pVisited[i][0] = true;
                qPacific.push({i, 0});
            }
        }
        for (int j = 0; j < col; j++) {
            if (!pVisited[0][j]) {
                pVisited[0][j] = true;
                qPacific.push({0, j});
            }
        }

        // Atlantic: bottom row + right column
        for (int i = 0; i < row; i++) {
            if (!aVisited[i][col - 1]) {
                aVisited[i][col - 1] = true;
                qAtlantic.push({i, col - 1});
            }
        }
        for (int j = 0; j < col; j++) {
            if (!aVisited[row - 1][j]) {
                aVisited[row - 1][j] = true;
                qAtlantic.push({row - 1, j});
            }
        }

        auto bfs = [&](vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
            vector<pair<int, int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(auto [dr, dc] : dirs){
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr >= 0 && nr < row && nc >= 0 && nc < col){
                        if(!visited[nr][nc] && heights[nr][nc] >= heights[r][c]){
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        };

        bfs(pVisited, qPacific);
        bfs(aVisited, qAtlantic);

        vector<vector<int>> res;
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col; j++){
                if(pVisited[i][j] && aVisited[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
