
vowels = "aeiou"
first = True
while True:
    try:
        vm = {}
        cm = {}
        n = int(input())
        if first == False:
            print("--")
        first = False
        for i in range(n):
            s = input().lower()
            for c in s:
                if c in vowels:
                    if c in vm:
                        vm[c] -= 1
                    else:
                        vm[c] = -1
                else:
                    if c in cm:
                        cm[c] -= 1
                    else:
                        cm[c] = -1
        cl = [y[0] for y in sorted(cm.items(), key=lambda x:(x[1],x[0]))]
        print(' '.join(cl))
        vl = [y[0] for y in sorted(vm.items(), key=lambda x:(x[1],x[0]))]
        print(' '.join(vl))
    except EOFError:
        break

