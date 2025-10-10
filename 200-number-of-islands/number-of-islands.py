class Solution:
    def bfs (self, grid: List[List[str]], i: int, j: int, visited: List[List[bool]]) -> None:
        row = len(grid)
        col = len(grid[0])

        visited[i][j] = True

        queue = deque()
        queue.append((i,j))

        x = [-1, 0, 1, 0]
        y = [0, 1, 0, -1]

        while queue:
            r, c = queue.popleft()

            for i in range(4):
                nr = r + x[i]
                nc = c + y[i]

                if 0 <= nr < row and 0 <= nc < col and visited[nr][nc] == False and grid[nr][nc] == '1':
                    visited[nr][nc] = True
                    queue.append((nr,nc))

    def numIslands(self, grid: List[List[str]]) -> int:
        row = len(grid)
        col = len(grid[0])

        count = 0

        visited = [[False for _ in range(col)] for _ in range(row)]

        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1' and visited[i][j] == False:
                    count += 1
                    self.bfs(grid, i, j, visited)

        return count