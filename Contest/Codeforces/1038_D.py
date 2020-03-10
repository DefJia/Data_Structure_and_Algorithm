a = int(input())
b = input().split()
for i in range(len(b)):
    b.append(int(b[0]))
    del b[0]

if len(b) > 1:
    x = max(b)
    n = min(b)
    s = 0
    for i in b:
        if i > 0:  s+= i
        else: s-=i
    if n > 0:
        s -= n*2
    if x < 0:
        s += x*2
else:
    s = b[0]

print(s)