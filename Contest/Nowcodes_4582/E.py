a = input().split()
data = dict()
for i in range(int(a[0])):
    q = input()
    data[q] = 0
for i in range(int(a[1])):
    q = input()
    if q in data:
        print('YES')
    else:
        print('NO')

