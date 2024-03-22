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


def make_allowed_move():
    pass


"""
    In Python, negative indexing allows you to access elements from the end of a list. So when you use rods['A'][-1], 
    it's accessing the last element of the list associated with the key 'A'.
"""

def move(n, source, auxiliary, target):
    # display starting configuration
    print(rods)
    for i in range(number_of_moves):
        remainder = (i + 1) % 3

        if remainder == 1:  # 1 divided by 3: 3*0 = 0, one minus cero = 1, thus remainder = 1

            print(f'Move {i+1} allowed between {source} and {target}')
            forward = False
            if not rods[target]:
                forward = True
            elif rods[source] and rods[source][-1] < rods[target][-1]:
                forward = True
            if forward:
                print(f'Moving disk {rods[source][-1]} from {source} to {target}')
                rods[target].append(rods[source].pop())
            else:
                print(f'Moving disk {rods[target][-1]} from {target} to {source}')
                rods[source].append(rods[target].pop())
            # display our progress
            print(rods)
        elif remainder == 2:
            print(f'Move {i+1} allowed between {source} and {auxiliary}')
        elif remainder == 0:
            print(f'Move {i+1} allowed between {auxiliary} and {target}')


# initiate call from source A to target C with auxiliary B
move(NUMBER_OF_DISKS, 'A', 'B', 'C')



