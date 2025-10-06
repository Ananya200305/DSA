class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix.reverse()
        
        l = len(matrix)

        for i in range(l):
            for j in range(i):
                matrix[i][j],matrix[j][i] = matrix[j][i], matrix[i][j]
        