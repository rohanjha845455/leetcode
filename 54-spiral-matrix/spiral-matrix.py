from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        result = []
        row_start, row_end = 0, len(matrix) - 1
        col_start, col_end = 0, len(matrix[0]) - 1

        while row_start <= row_end and col_start <= col_end:
            # Traverse Right
            for col in range(col_start, col_end + 1):
                result.append(matrix[row_start][col])
            row_start += 1

            # Traverse Down
            for row in range(row_start, row_end + 1):
                result.append(matrix[row][col_end])
            col_end -= 1

            # Traverse Left
            if row_start <= row_end:
                for col in range(col_end, col_start - 1, -1):
                    result.append(matrix[row_end][col])
                row_end -= 1

            # Traverse Up
            if col_start <= col_end:
                for row in range(row_end, row_start - 1, -1):
                    result.append(matrix[row][col_start])
                col_start += 1

        return result
