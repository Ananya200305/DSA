class Solution {
public:
    vector<vector<int>> bfs(vector<vector<int>>& image, vector<vector<int>> visited, queue<pair<int, int>>q, int color, int startColor){
        int row = image.size();
        int col = image[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nRow = r + delRow[k];
                int nCol = c + delCol[k];

                if(nRow >= 0 && nRow < row 
                && nCol >= 0 && nCol < col
                && image[nRow][nCol] == startColor
                && !visited[nRow][nCol]){
                    visited[nRow][nCol] = 1;
                    image[nRow][nCol] = color;
                    q.push({nRow, nCol});
                }
            }
        }

        return visited;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));
        queue<pair<int, int>>q;

        int startColor = image[sr][sc];
        if(startColor == color) return image;

        visited[sr][sc] = 1;
        image[sr][sc] = color;
        q.push({sr,sc});

        bfs(image, visited, q, color, startColor);

        return image;
    }
};