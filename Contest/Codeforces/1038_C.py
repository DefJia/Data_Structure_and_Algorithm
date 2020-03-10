a = input()
bb = input().split()
cc = input().split()
b = list()
c = list()
for i in bb: b.append(int(i))
for i in cc: c.append(int(i))
b.sort()
c.sort()
q = 0
w = 0
for i in range(int(a)):
    if len(c) == 0: c.append(0)
    if len(b) == 0: b.append(0)
    if b[len(b)-1] > c[len(c)-1]:
        q += b[len(b)-1]
        del b[len(b)-1]
    else:
        del c[len(c)-1]
    if len(c) == 0: c.append(0)
    if len(b) == 0: b.append(0)
    if c[len(c)-1] > b[len(b)-1]:
        w += c[len(c)-1]
        del c[len(c)-1]
    else:
        del b[len(b)-1]
print(q-w)
