from collections import defaultdict
from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        for i in range(9):
            row_count = defaultdict(int)
            col_count = defaultdict(int)
            for j in range(9):
                # row check
                if board[i][j] != '.':
                    row_count[board[i][j]] += 1
                    if row_count[board[i][j]] > 1:
                        return False
                        
                if board[j][i] != '.':
                    col_count[board[j][i]] += 1
                    if col_count[board[j][i]] > 1:
                        return False
        
        # check 3x3 boxes
        for box_row in [0,3,6]:
            for box_col in [0,3,6]:
                box_count = defaultdict(int)
                for i in range(3):
                    for j in range(3):
                        val = board[box_row+i][box_col+j]
                        if val != '.':
                            box_count[val] += 1
                            if box_count[val] > 1:
                                return False
        return True
