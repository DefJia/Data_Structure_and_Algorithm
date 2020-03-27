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

