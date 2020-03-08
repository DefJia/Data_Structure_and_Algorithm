a = input().split()
n = int(a[0])
k = int(a[1])
a = n % (2*k+1)
b = int(n/(2*k+1))
lst = []
if a == 0:
    flag = 0
    cnt = b
    for i in range(b):
        lst.append((2*k+1)*i+k+1)
elif b == 0:
    flag = 1
    cnt = 1
    lst.append(int(a/2)+1)
elif a < (k+1):
    cnt = b + 1
    for i in range(cnt):
        lst.append((2 * k + 1) * i + 1)
else:
    cnt = b + 1
    for i in range(cnt):
        lst.append((2 * k + 1) * i + (a-k))

print(cnt)
ii = 0
for i in lst:
    ii += 1
    if ii == len(lst):
        print(i)
        break
    print(i, end=' ')