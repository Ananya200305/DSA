class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        firstRow = False
        firstCol = False

        row = len(matrix)
        col = len(matrix[0])

        for i in range(row):
            if matrix[i][0] == 0:
                firstCol = True

        for i in range(col):
            if matrix[0][i] == 0:
                firstRow = True

        for i in range(1, row):
            for j in range(1, col):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        for i in range(1,row):
            for j in range(1,col):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        if firstRow:
            for i in range(col):
                matrix[0][i] = 0

        if firstCol:
            for i in range(row):
                matrix[i][0] = 0
        