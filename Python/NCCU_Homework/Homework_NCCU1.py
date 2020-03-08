"""
    http://codeta.ml/contest/10/problem/hw303
"""
a = int(input())
while(a):
    a -= 1
    b = input()
    c = b.split('@')
    x = c[0]
    e = c[1].split('.')
    y = e[0]
    z = e[1]
    flag = 0
    for i in x:
        if not (i.isdigit() or i.islower() or i in ('_', '-')):
            flag = 1
    for i in y:
        if not (i.isdigit() or i.islower()):
            flag = 1
    if len(z) > 3:
        flag = 1
    if flag == 1:
        print('Invalid')
    else:
        print('Valid')