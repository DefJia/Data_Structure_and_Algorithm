def find(a, b):
    c = []  # gap
    for i in range(1, len(a)):
        if i not in b:
            c.append(i)
    flag = 0
    lmax = 0
    if c:
        for ii in range(0, c[0]):
            if a[ii] > lmax:
                lmax = a[ii]


        for i in range(0, len(c)-1):    
            min = 100
            max = 0
            for ii in range(c[i], c[i+1]):
                if a[ii] > max: max = a[ii]
                if a[ii] < min: min = a[ii]
            if lmax > min:
                flag = 1
                break
            lmax = max

        min = 100
        for ii in range(c[-1], len(a)):
            if a[ii] < min:
                min = a[ii]
        if min < lmax:
            flag = 1
    
    
    if flag == 1:
        print('NO')
    else:
        print('YES')

a = int(input())
for i in range(a):
    b = input()
    c = input().split(' ')
    d = input().split(' ')
    for i in range(len(c)):
        c[i] = int(c[i])
    for i in range(len(d)):
        d[i] = int(d[i])
    d.sort()
    find(c, d)

    
        
        

