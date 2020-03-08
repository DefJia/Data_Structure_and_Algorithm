if __name__ == '__main__':
    a = int(input())
    b = input().split()
    c = list()
    for i in b:
        c.append(int(i))
    s = sum(c)
    flag = 1
    while c and flag:
        c.sort(reverse=True)
        cur = c[0]
        if c[0] >= len(c):
            flag = 0
        c = c[1:]
        for i in range(len(c)):
            if cur:
                cur -= 1
                if c[i] < 0:
                    flag = 0
                    break
                c[i] -= 1
            else:
                break
    if flag == 1 and s % 2 == 0:
        print('yes')
    else:
        print('no')