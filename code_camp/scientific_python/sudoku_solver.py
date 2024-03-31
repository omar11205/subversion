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
                

