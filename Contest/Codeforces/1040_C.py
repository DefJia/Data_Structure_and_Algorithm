def catch(start, end, n, k):
    diff = end - start
    print("%d %d" % (start, end))
    a = input()
    if 'Yes' in a:
        return max(1, start-k), min(n, int(start+diff/2))
    else:
        return max(1, end+1-k), min(n, end+1-k+diff+k)

a = input().split()
n = int(a[0])
k = int(a[1])

ran = int(n / 2) + 1
start = 1
flag = 1
# a, b = catch(1, n, n, k)
a = max(1, 1-k)
b = min(n, int(1+(n-1)/2))
def hhh(a, b, n, k):
    while (b - a) > 2 * k:
        a, b = catch(a, b, n, k)
    return a, b

c = ''
while 'Yes' not in c:
    a, b = hhh(max(1, a-k), min(n,b+k),n, k)
    v = int((a + b) / 2)
    print("%d %d" % (v, v))
    c = input()

import sys
sys.stdout.flush()