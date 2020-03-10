a = input().split()
b = input()
c = dict()
for i in range(int(a[1])):
    c[chr(65+i)] = 0
for i in b:
    c[i] += 1
q = min(c.items(), key=lambda x: x[1])[1]
print(q*int(a[1]))

