"""
    The goal of the Tower of Hanoi is moving all the disks to the last rod. To do that, you must follow three simple rules:

    You can move only top-most disks
    You can move only one disk at a time
    You cannot place larger disks on top of smaller ones

"""
NUMBER_OF_DISKS = 5
# minimum theoretical number of moves = 2^n - 1, where n = number of disks
number_of_moves = 2**NUMBER_OF_DISKS - 1

rods = {
    'A': list(range(NUMBER_OF_DISKS, 0, -1)),  # create a list from range 3 to 1 descending representing the initial state
    'B': [],
    'C': []
}

A = list(range(NUMBER_OF_DISKS, 0, -1))
B = []
C = []


# this algorithm controls the movements from one disk to another
def make_allowed_move(rod1, rod2):
    forward = False
    if not rods[rod2]:
        forward = True
    elif rods[rod1] and rods[rod1][-1] < rods[rod2][-1]:
        forward = True
    if forward:
        print(f'Moving disk {rods[rod1][-1]} from {rod1} to {rod2}')
        rods[rod2].append(rods[rod1].pop())
    else:
        print(f'Moving disk {rods[rod2][-1]} from {rod2} to {rod1}')
        rods[rod1].append(rods[rod2].pop())
    # display our progress
    print(rods, '\n')


"""
    In Python, negative indexing allows you to access elements from the end of a list. So when you use rods['A'][-1], 
    it's accessing the last element of the list associated with the key 'A'.
"""


# The next algorithm is ok for n=3 roads in tower of hanoi
def move(n, source, auxiliary, target):
    # display starting configuration
    print(rods, '\n')
    for i in range(number_of_moves):
        remainder = (i + 1) % 3
        if remainder == 1:  # 1 divided by 3: 3*0 = 0, one minus cero = 1, thus remainder = 1
            print(f'Move {i+1} allowed between {source} and {target}')
            make_allowed_move(source, target)
        elif remainder == 2:
            print(f'Move {i+1} allowed between {source} and {auxiliary}')
            make_allowed_move(source, auxiliary)
        elif remainder == 0:
            print(f'Move {i+1} allowed between {auxiliary} and {target}')
            make_allowed_move(auxiliary, target)


# this algorithm is a modified version of n=4 in tower of hanoi
def move_four(n, source, auxiliary, target):
    # display starting configuration
    print(rods, '\n')
    for i in range(number_of_moves):
        remainder = (i + 1) % 3
        if remainder == 1:
            if n % 2 != 0:
                print(f'Move {i + 1} allowed between {source} and {target}')
                make_allowed_move(source, target)
            else:
                print(f'Move {i + 1} allowed between {source} and {auxiliary}')
                make_allowed_move(source, auxiliary)
        elif remainder == 2:
            if n % 2 != 0:
                print(f'Move {i + 1} allowed between {source} and {auxiliary}')
                make_allowed_move(source, auxiliary)
            else:
                print(f'Move {i + 1} allowed between {source} and {target}')
                make_allowed_move(source, target)
        elif remainder == 0:
            print(f'Move {i + 1} allowed between {auxiliary} and {target}')
            make_allowed_move(auxiliary, target)


"""
    To solve the puzzle for any n with recursion, the first thing to do is break the original problem down into smaller 
    sub-problems.

    The final configuration with n disks piled up to the third rod in decreasing order can be obtained by moving:

    n - 1 disks from the source to the auxiliary rod
    the largest disk from the source to the target
    and then the n - 1 disks from the auxiliary rod to the target.
    So, the first thing the move function should do is calling itself with n - 1 as the first argument. 
    But if you try to do so without defining a base case, you will get a RecursionError. 
    This happens because the function keeps calling itself indefinitely
"""


def move_general(n, source, auxiliary, target):
    if n <= 0:
        return

    # move n-1 disks from source to auxiliary, so they are out of the way
    move_general(n-1, source, target, auxiliary)

    # move the nth disk from source to target
    target.append(source.pop())

    # display starting configuration
    print(A, B, C, '\n')

    # move the n - 1 disks that we left on auxiliary onto target
    move_general(n - 1, auxiliary, source, target)


# initiate call from source A to target C with auxiliary B (n=3)
# move(NUMBER_OF_DISKS, 'A', 'B', 'C')

# initiate call from source A to target C with auxiliary B (n=4)
# move_four(NUMBER_OF_DISKS, 'A', 'B', 'C')

# initiate call from source A to target C with auxiliary B (n)
move_general(NUMBER_OF_DISKS, A, B, C)

