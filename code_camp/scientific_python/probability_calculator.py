import copy
import random

"""
    For this project, you will write a program to determine the approximate probability of drawing certain balls 
    randomly from a hat.
"""


class Hat:
    def __init__(self, **kwargs):
        self.contents = []
        for color, count in kwargs.items():
            self.contents.extend([color] * count)

    def draw(self, num_balls):
        drawn_balls = []
        if num_balls >= len(self.contents):
            drawn_balls = self.contents
            self.contents = []
        else:
            for _ in range(num_balls):
                ball_index = random.randrange(len(self.contents))
                drawn_balls.append(self.contents.pop(ball_index))
        return drawn_balls


def experiment(hat, expected_balls, num_balls_drawn, num_experiments):
    successful_experiments = 0

    for _ in range(num_experiments):
        hat_copy = copy.deepcopy(hat)
        drawn_balls = hat_copy.draw(num_balls_drawn)
        drawn_dict = {color: drawn_balls.count(color) for color in set(drawn_balls)}

        success = True
        for color, count in expected_balls.items():
            if drawn_dict.get(color, 0) < count:
                success = False
                break

        if success:
            successful_experiments += 1

    return successful_experiments / num_experiments


hat = Hat(black=6, red=4, green=3)
probability = experiment(hat=hat, expected_balls={"red": 2, "green": 1}, num_balls_drawn=5, num_experiments=2000)
print(probability)
