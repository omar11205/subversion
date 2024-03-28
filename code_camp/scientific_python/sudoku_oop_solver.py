class SudokuSolver:
    def __init__(self, board):
        self.board = board
        self.size = len(board)
        self.empty_cell = 0

    def solve(self):
        if not self._solve_recursive():
            print("No solution exists")
        else:
            self._print_board()

    def _solve_recursive(self):
        empty_cell = self._find_empty()
        if not empty_cell:
            return True  # Puzzle solved
        else:
            row, col = empty_cell

        for num in range(1, self.size + 1):
            if self._is_valid(num, (row, col)):
                self.board[row][col] = num
                if self._solve_recursive():
                    return True
                self.board[row][col] = self.empty_cell  # Backtrack
        return False

    def _find_empty(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.board[i][j] == self.empty_cell:
                    return (i, j)  # (row, col)
        return None

    def _is_valid(self, num, position):
        # Check row
        for i in range(self.size):
            if self.board[position[0]][i] == num and position[1] != i:
                return False

        # Check column
        for i in range(self.size):
            if self.board[i][position[1]] == num and position[0] != i:
                return False

        # Check square
        box_x = position[1] // 3
        box_y = position[0] // 3
        for i in range(box_y * 3, box_y * 3 + 3):
            for j in range(box_x * 3, box_x * 3 + 3):
                if self.board[i][j] == num and (i, j) != position:
                    return False
        return True

    def _print_board(self):
        for i in range(self.size):
            if i % 3 == 0 and i != 0:
                print("-" * (self.size + 2))
            for j in range(self.size):
                if j % 3 == 0 and j != 0:
                    print("|", end=" ")
                print(self.board[i][j], end=" ")
            print()


# Example usage:
if __name__ == "__main__":
    board = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]
    ]

    solver = SudokuSolver(board)
    print("Sudoku puzzle to solve:")
    solver._print_board()
    print("\nSolving...\n")
    solver.solve()