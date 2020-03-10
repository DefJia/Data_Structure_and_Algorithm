a = int(input())

def c(a, b):
    if a == b:
        return 0
    elif a < b:
        if (b-a) % 2 == 1:
            return 1
        else:
            return 2
    else:
        if (a-b) % 2 == 1:
            return 2
        else:
            return 1
a = int(input())
for i in range(a):
    b = input().split(' ')
    d = c(int(b[0]), int(b[1]))
    print(d)



