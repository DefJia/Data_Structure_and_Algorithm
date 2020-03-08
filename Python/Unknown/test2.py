if __name__ == '__main__':
    a = int(input())
    b = input().split()
    c = list()
    for i in b:
        c.append(int(i))
    c.sort()
    total = 0
    for i in range(int(a/2)):
        tmp = c[i] + c[a-1-i]
        total += pow(tmp, 2)
    print(total)