n = int(input())
for i in range(n):
    l = list(map(int, input().split()))
    print([x for x in l if l.count(x) == 1][0])
