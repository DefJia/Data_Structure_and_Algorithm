a = input().split()
n = int(a[0])
k = int(a[1])

b = int(k/n)
if b > k/n: b-= 1
if k % n != 0:
    b += 1
print(b)

