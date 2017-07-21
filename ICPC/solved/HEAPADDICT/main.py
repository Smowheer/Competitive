import sys
import math

def lp2(x):
    return int(math.pow(2, math.floor(math.log(x, 2))))

def binom(n, k):
    return math.factorial(n) / (math.factorial(n-k) * math.factorial(k))

def heap(x):
    if x <= 2:
        return 1
    elif x == 3:
        return 2
    else:
        lp = lp2(x) 
        a = lp/2 + x-lp
        b = x-1 - a
        if a > lp-1:
            b += a - lp + 1
            a = lp-1
        return binom(x-1, a) * heap(a) * heap(b)
    

for line in sys.stdin:
    x = int(line)
    print(heap(x))
