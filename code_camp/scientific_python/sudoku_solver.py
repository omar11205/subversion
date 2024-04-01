class Board:
    def __init__(self, board):
        self.board = board

    def __str__(self):
        upper_lines = f'\n╔═══{"╤═══" * 2}{"╦═══"}{"╤═══" * 2}{"╦═══"}{"╤═══" * 2}╗\n'
        middle_lines = f'╟───{"┼───" * 2}{"╫───"}{"┼───" * 2}{"╫───"}{"┼───" * 2}╢\n'
        lower_lines = f'╚═══{"╧═══" * 2}{"╩═══"}{"╧═══" * 2}{"╩═══"}{"╧═══" * 2}╝\n'
        board_string = upper_lines

        """
        Enumeration is a convenient way to keep track of both the element and its position on a list. The enumerate() 
        function is a built-in function in Python that takes an iterable (such as a list, tuple, or string) and returns 
        an iterator that produces tuples containing indices and corresponding values from the iterable.
        """
        for index, line in enumerate(self.board):
            row_list = []
            for square_no, part in enumerate([line[:3], line[3:6], line[6:]], start=1):
                for item in part:
                    row_square = '|'.join(str(item) for item in part)
                    row_list.extend(row_square)
                    if square_no != 3:
                        row_list.append('║')

                row = f'║ {" ".join(row_list)} ║\n'
                row_empty = row.replace('0', ' ')
                board_string += row_empty

                if index < 8:
                    if index % 3 == 2:
                        board_string += f'╠═══{"╪═══" * 2}{"╬═══"}{"╪═══" * 2}{"╬═══"}{"╪═══" * 2}╣\n'
                    else:
                        board_string += middle_lines
                else:
                    board_string += lower_lines
        return board_string

    # method who finds the empty cells in the sudoku board
    def find_empty_cell(self):
        for row, contents in enumerate(self.board):
            try:
                col = contents.index(0)
                return row, col
            except ValueError:
                pass
        return None

    # method that checks if a given number can be inserted into a specific row of the sudoku board
    def valid_in_row(self, row, num):  # row = row index, num = number to be checked
        return num not in self.board[row]

    # method that checks if a number can be inserted in a specified column of the sudoku board
    def valid_in_col(self, col, num):  # col = column index, num = number to be checked
        # all(generator_expression) checks if all the elements generated by the generator_expression (list) are True,
        # and return True, otherwise return false
        all(self.board[row][col] != num for row in range(9))

    # method to check if the number is valid (not repeated) in a 3x3 square
    def valid_in_square(self, row, col, num):  # row = row index, col = column index, num = number to be checked
        """
            Now you need to calculate the starting row index for the 3x3 block in the board grid. For that, ensure that
            the starting row index for each 3x3 block is a multiple of 3. This can be achieved by this mathematical
            operation: (row // 3) * 3.
        """
        row_start = (row // 3) * 3  # check for similar logic in (Buritica, p 134, 2023)
        col_start=(col // 3) * 3
        for row_no in range(row_start, row_start + 3):
            for col_no in range(col_start, col_start + 3):
                if self.board[row_no][col_no] == num:
                    return False
        return True

    # method to check if a given number is a valid choice for an empty cell in the sudoku board by validating its
    # compatibility wi the row, column, and 3x3 square of the specified empty cell
    def is_valid(self, empty, num):  # empty = a tuple representing the row and column indices of an empty cell, num =
        # number to be checked
        pass

