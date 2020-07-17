######################
#     _        ____  #
# U  /"\  u U /"___| #
#  \/ _ \/  \| | u   #
#  / ___ \   | |/__  #
# /_/   \_\   \____| #
#  \\    >>  _// \\  #
# (__)  (__)(__)(__) #
# Compro by NULL_CT© #
######################
from sys import stdin
import numpy as np
import math

input = stdin.readline

def divisor(_n):
    result = []
    for i in range(1, int(math.sqrt(_n)) + 1):
        if _n % i == 0:
            result.append(i)
            if _n % (_n / i) == 0:
                result.append(int(_n / i))
    return result

k,x = map(int,input().split())

if 500 * k >= x:
    print("Yes")
else:
    print("No")
