if __name__ == "__main__":
    a = int(input())
    for _ in range(a):
        b = input().split()
        max = int(b[1])
        c = input().split()
        sum = 0
        for i in c:
            sum += int(i)
        if sum > max:
            print(max)
        else:
            print(sum)