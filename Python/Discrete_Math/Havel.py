if __name__ == '__main__':  
    a = int(input())
    b = input().split()
    c = list()
    for i in b:
        c.append(int(i))
    c.sort(reverse=True)
    flag = 0
    for i in range(len(c)):
        if c[i] < 0 or i+c[i] > len(c):
            flag = 1
        for ii in range(i+1, i+1+c[i]):
            c[ii] -= 1
    if flag * sum(c) % 2 == 0:
        print('yes')
    else:  
        print('no')
