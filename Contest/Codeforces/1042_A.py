a = int(input())
b = int(input())
lst = []
total = 0
for i in range(a):
    tmp = int(input())
    lst.append(tmp)
    total += tmp
x = max(lst)
n = min(lst)
big = x + b
if total <= a * x - b:
    small = x
else:
    tmp = b - (a * x - total)
    small = int(tmp/a)+x
    if tmp % a != 0 : small+=1
print("%d %d" % (small, big))