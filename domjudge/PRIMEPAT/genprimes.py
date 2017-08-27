def isPrime(x):
    if x == 1: return False
    elif x == 2: return True
    for i in range(2, x):
        if x % i == 0: return False
    return True

def onediff(a, b):
    s = 0
    while(a != 0):
        s += a % 10 == b % 10
        a //= 10
        b //= 10
    if s == 3: return True
    else: return False

primes = [x for x in range(1000,9999) if isPrime(x)]

print("{", end="")
print(str(primes[0])+":0",end="")
for i in range(1, len(primes)):
    print(","+str(primes[i])+":"+str(i), end="")
print("}")

print("adj = {", end="")
for i in range(len(primes)):
    print(str(primes[i])+":", end="")
    for j in range(i+1, len(primes)):
        if (onediff(primes[i], primes[j])):
            print(str(primes[j]),end=",")
    print()
