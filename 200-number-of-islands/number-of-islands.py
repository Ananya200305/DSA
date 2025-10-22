class Solution:
    def bfs(self, grid: list[List[str]], i: int, j : int, visited: List[List[bool]]) -> None:
        row = len(grid)
        col = len(grid[0])

        q = deque()
        q.append((i,j))

        x = [-1, 0, 1, 0]
        y = [0, 1, 0, -1]

        while q:
            r,c = q.popleft()

            for i in range(4):
                nr = r + x[i]
                nc = c + y[i]

                if 0 <= nr < row and 0 <= nc < col and grid[nr][nc] == "1" and visited[nr][nc] == False:
                    visited[nr][nc] = True
                    q.append((nr,nc))

    def numIslands(self, grid: List[List[str]]) -> int:
        row = len(grid)
        col = len(grid[0])

        visited = [[False for _ in range(col)] for _ in range(row)]

        count = 0

        for i in range(row):
            for j in range(col):
                if grid[i][j] == "1" and visited[i][j] == False:
                    count += 1
                    self.bfs(grid, i, j, visited)

        return count