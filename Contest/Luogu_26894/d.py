a = int(input())

b = [[0 for i in range(a)] for ii in range(a)]

cur = [0, 0]
num = 1
q = a-1

while q >= 1:
    for i in range(q):
        b[cur[0]][cur[1]] = num
        cur[1] += 1
        num += 1
    for i in range(q):
        b[cur[0]][cur[1]] = num
        cur[0] += 1
        num += 1
    for i in range(q):
        b[cur[0]][cur[1]] = num
        cur[1] -= 1
        num += 1
    for i in range(q):
        b[cur[0]][cur[1]] = num
        cur[0] -= 1
        num += 1
    cur[0] += 1
    cur[1] += 1
    q -= 2

if q == 0:
    b[cur[0]][cur[1]] = num

flag = 2 if a <= 3 else 1

for i in b:
    q = ''
    for ii in i:
        a = '{0:3d}'.format(ii)
        q += a
    print(q)
