'''
a = input().split()
data = dict()
for i in range(int(a[0])):
    q = input()
    data[q] = 0
for i in range(int(a[1])):
    q = input()
    if q in data:
        print('YES')
    else:
        print('NO')

from datetime import datetime

a = int(input())
for _ in range(a):
    q = input().split()
    r = [int(i) for i in q]
    z = input().split('-')
    p = datetime(2020, 2, 23)
    cday = datetime(int(z[0]), int(z[1]), int(z[2]))
    w = cday.weekday()
    s = (cday - p).days
    cnt = 0
    if s > 7:
        cnt += sum(r) * (s//7)
    for j in range(min(5, s%7)):
        cnt += r[j]
    print(cnt)


if __name__ == "__main__":
    a = get(1)[0][0]
    a, b, c,d  = a[0], a[1], a[2], a[3]
    q = 1
    m = 10 ** 9 + 7
    if c:
        if d == a and d == b:
            q = c
        elif d in (a, b):
            for i in range(c):
                q = q * 2
            q = (q * c // 2) % m
        else:
            q = 0
    else:
        q = 0
    print(q)



if __name__ == "__main__":
    w = get(0, 1, 3, 3)
    for i in w:
        a = i[1]
        b = i[2]
        n = i[0][0]
        # c = [0, 0, 0,0] # cg gc au ua
        c = dict()
        for p in 'CGAU':
            c[p] = 0
        cnt = 0
        for j in range(n):
            if (a[j], b[j]) not in [('A', 'U'), ('G', 'C'), ('U', 'A'), ('C', 'G')]:
                if a[j] == b[j]:
                    c[b[j]] += 1
                else:
                    cnt += 1
        cnt += max(c['A'], c['U']) + max(c['G'], c['C'])
        print(cnt)



if __name__ == "__main__":
    import heapq
    def findKthLargest(nums, k):
        return heapq.nlargest(k, nums)[-1]
    def findKthSmallest(nums, k):
        return heapq.nsmallest(k, nums)[-1]
    
    w = get(1,1,1)[0]
    n = w[0][0]
    k = w[0][1]
    fx = w[1]
    sc = w[2]
    q = findKthLargest(sc, k)  # 生产阈值
    nfx = 0; nsc = 0; nn = 0
    afx = list()
    for i in range(n):
        if sc[i] > q:
            nfx += fx[i]
            nsc += sc[i]
            nn += 1
        elif sc[i] == q:
            afx.append(fx[i])
    yu = k - nn
    nsc += yu * q
    q = findKthSmallest(afx, yu)
    n = 0
    for i in afx:
        if i < q:
            nfx += i
            n += 1
    yu -= n
    nfx += q * yu
    print(nfx, nsc)

    '''

def get(*arg):
    if arg[0] == 0:
        cnt = int(input())
        flag = 1
    else:
        cnt = 1
        flag = 0
    lst = list()
    for i in range(cnt):
        lst2 = list()
        for ii in range(len(arg)-flag):
            if arg[ii+flag] == 1:
                t = input().split()
                tmp = list()
                for iii in t:
                    tmp.append(int(iii))
            elif arg[ii+flag] == 2:
                tmp = input().split()
            else:
                tmp = input()
            lst2.append(tmp)
        lst.append(lst2)
    return lst


if __name__ == "__main__":
    x = get(0, 1)
    z = input()
    y = get(0, 1)
    data = dict()
    data2 =dict()
    rank = list()
    n = 1
    for i in x:
        for j in i[0]:
            data[j] = n
        n += len(i[0])
    n = 1
    for i in y:
        for j in i[0]:
            if j in data.keys():
                data2[j] = (data[j] + n) / 2
                del data[j]
            else:
                data[j] = -n
        n += len(i[0])
    a = sorted(data2.items(), key = lambda kv:(kv[1], kv[0]))
    for i in a:
        for j in x+y:
            if i[0] in j[0]:
                for k in j[0]:
                    if k in data.keys():
                        if k in data2.keys():
                            if data2[k] == i[1]:
                                pass
                            else:
                                del data[k]
                                del data2[k]
                        else:
                            data2[k] = i[1] 
    t = list()
    for i in data.keys():
        if i in data2.keys():
            t.append(i)
    for i in t:
        del data[i]
    a = sorted(data2.items(), key = lambda kv:(kv[1], kv[0]))
    data3 = dict()
    for i in a:
        data3[i[0]] = i[1]
    tmp = list()
    tmp2 = list()
    for i in data:
        flag = 0
        c = x if data[i] > 0 else y
        xiao = 101; da = 0
        for j in c:
            if i in j[0]:
                flag = 1
            elif flag == 0:
                for k in j[0]:
                    if k in data3:
                        da = max(data3[k], da)
            else:
                for k in j[0]:
                    if k in data3:
                        xiao = min(data3[k], xiao)
                    if xiao <= da:
                        # 不能排
                        flag = -1
                        tmp.append(i)
                        break
            if flag < 0:
                break
        if flag >= 0:
            # 在a中找位置 负数
            for j in range(len(a)-1):
                if a[j][1] == da and a[j+1][1] == xiao:
                    tmp2.append(((a[j][1],a[j+1][1]), (i, data[i])))
                    break
                if xiao == 101:
                    tmp2.append((101, (i, data[i])))
                    break
                elif da == 0:
                    tmp2.append((0, (i, data[i])))
                    break
    for i in tmp:
        del data[i]
        
    res = list()
    t = list()
    for i in tmp2:
        if i[0] == 0:
            t.append((i[1][0], abs(i[1][1])))
    b = sorted(t, key = lambda kv:(kv[1], kv[0]))
    tmp2 = [i for i in tmp2 if i[0] != 0]
    cur = b[0][1]
    res.append([])
    for i in b:
        if i[1] == cur:
            res[-1].append(i[0])
        else:
            cur = i[1]
            res.append([i[0]])

    cur = a[0][1]
    res.append([])
    for i in range(len(a)):
        if a[i][1] == cur:
            res[-1].append(a[i][0])
        else:
            res.append([])
            res[-1].append(a[i][0])
            cur = a[i][1]
        if i != len(a)-1:
            tmp3 = list()
            for j in tmp2:
                if j[0] == (a[i][1], a[i+1][1]):
                    tmp3.append((j[1][0], abs(j[1][1])))
            if tmp3:
                b = sorted(tmp3, key = lambda kv:(kv[1], kv[0]))
                cur_ = b[0][1]
                res.append([])
                for i in b:
                    if i[1] == cur_:
                        res[-1].append(i[0])
                    else:
                        cur_ = i[1]
                        res.append([i[0]])

    t = list()
    for i in tmp2:
        if i[0] == 101:
            t.append((i[1][0], abs(i[1][1])))
    b = sorted(t, key = lambda kv:(kv[1], kv[0]))
    cur = b[0][1]
    res.append([])
    for i in b:
        if i[1] == cur:
            res[-1].append(i[0])
        else:
            cur = i[1]
            res.append([i[0]])

    for i in res:
        print(*i)
            