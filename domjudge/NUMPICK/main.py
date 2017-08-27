from fractions import Fraction
n = int(input())
for i in range(n):
    num, den = list(map(int, input().split()))
    f1 = Fraction(num, den)
    num, den = list(map(int, input().split()))
    f2 = Fraction(num, den)
    f3 = (f1 + f2) / 2
    print(f3.numerator, f3.denominator)
