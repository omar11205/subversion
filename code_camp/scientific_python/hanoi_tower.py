"""
    The goal of the Tower of Hanoi is moving all the disks to the last rod. To do that, you must follow three simple rules:

    You can move only top-most disks
    You can move only one disk at a time
    You cannot place larger disks on top of smaller ones

"""
NUMBER_OF_DISKS = 3
# minimum theoretical number of moves = 2^n - 1, where n = number of disks
number_of_moves = 2**NUMBER_OF_DISKS - 1

rods = {
    'A': list(range(3, 0, -1)),  # create a list from range 3 to 1 descending representing the initial state
    'B': [],
    'C': []
}

def move(n, source, auxiliary, target):
    # display starting configuration
    print(rods)
    for i in range(number_of_moves):
        if (i+1) % 3 == 1:
            print(f'Move {i+1} allowed between {source} and {target}')

# initiate call from source A to target C with auxiliary B
move(NUMBER_OF_DISKS, 'A', 'B', 'C')



