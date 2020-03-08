if __name__ == '__main__':
    a = int(input())
    m = list()
    for i in range(a):
        tmp = input()
        m.append(tmp)
    count = 0
    for i in range(1, a-1):
        for j in range(1, a-1):
            if m[i-1][j-1] + m[i+1][j+1] + m[i-1][j+1] + m[i+1][j-1] + m[i][j]== 'XXXXX':
                count += 1
    print(count)