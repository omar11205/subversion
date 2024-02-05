import math
import matplotlib.pyplot as plt
import numpy as np

# 1.  prove that 24 is fascinating for the reason that it is the greatest integer for which n!
# (factorial n) has exactly n decimal digits.
# 2. It is also the greatest integer n which is divisible
# by each integer not exceeding √n.
# 3. It is the only integer n (n>0) for which
# 1^2 + 2^2 ... + n^2 is a square
num = 100

for i in range(num+1):
    facto = math.factorial(i)
    length_num = len(str(facto))
    if i == length_num:
        print("The factorial of ", i, " is: ", facto, "and has: ", length_num, "digits")
    else:
        print("num = ", i, " length = ", length_num)

# further work: compare results with kamenetsky's formula to count digits in a factorial:
# https://thecoducer.com/2019/07/kamenetsky-formula-to-count-digits-in-factorial/

