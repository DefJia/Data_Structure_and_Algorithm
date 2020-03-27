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

'''
if __name__ == "__main__":
    q = get(0, 1)
    for i in q:
        a = i[0][0]; b = i[0][1]
        if a <= b:
            print(b - a)
        else:
            c = (a // b + 1) * b - a
            if c == b:
                c = 0
            print(c)
'''
import math
if __name__ == "__main__":
    a = get(0, 1)
    for i in a:
        n = i[0][0]; k = i[0][1]
        t = int(math.sqrt(k*2)) - 1
        tt = t * (t-1) // 2
        while tt < k:
            t += 1
            tt = t * (t-1) // 2
        t -= 1
        res = ['a' for i in range(n)]
        res[n-t-1] = 'b'
        res[n-(t-tt+k)] = 'b'
        print(''.join(res))