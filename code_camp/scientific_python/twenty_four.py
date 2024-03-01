import math
import matplotlib.pyplot as plt
import numpy as np

'''
     From Introduction to Number theory with computing (Allemby et al., 1989)
     1.  prove that 24 is fascinating for the reason that it is the greatest integer for which n!
     (factorial n) has exactly n decimal digits.
     2. It is the only integer n (n>0) for which 1^2 + 2^2 + ... + n^2 is a square
'''

num = 50+1  # inputs
a = np.empty(shape=(2, num), dtype=np.int32)  # np.array to store (number, number of digits of factorial(number))

for i in range(num):
    facto = math.factorial(i)
    length_facto = len(str(facto))
    a[:,  i] = [i, length_facto]
    print(a)
    if i == length_facto:
        print("The factorial of ", i, " is: ", facto, "and has: ", length_facto, "digits")
    else:
        print("num = ", i, " length = ", length_facto)

plt.scatter(a[0, :], a[1, :], marker='o')
plt.title('Scatter Plot of Factorial Digits')
plt.xlabel('Input Number (num)')
plt.ylabel('Number of Digits')
plt.show()

# further work: compare results with kamenetsky's formula to count digits in a factorial:
# https://thecoducer.com/2019/07/kamenetsky-formula-to-count-digits-in-factorial/
