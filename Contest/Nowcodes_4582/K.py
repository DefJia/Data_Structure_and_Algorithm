from datetime import datetime
 
a = int(input())
for _ in range(a):
    q = input().split()
    r = [int(i) for i in q]
    z = input().split('-')
    p = datetime(2020, 2, 24)
    cday = datetime(int(z[0]), int(z[1]), int(z[2]))
    w = cday.weekday()
    s = (cday - p).days
    cnt = 0
    if s >= 7:
        cnt += sum(r) * (s//7)
    for j in range(min(5, s%7+1)):
        cnt += r[j]
    print(cnt)

