def get(*arg):
    if arg[0] == 0:
        cnt = int(input())
        flag = 1
    else:
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
    a = get(0, 1, 1, 1)
    for _ in range(len(a)):
        cur = a[_]
        b = sorted(cur[1])
        c = sorted(cur[2])
        print(*b)
        print(*c)