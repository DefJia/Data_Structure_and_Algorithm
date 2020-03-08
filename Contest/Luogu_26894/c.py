def get_list():
    a = input().split(' ')
    b = []
    for i in a:
        b.append(int(i))
    return b


a = get_list()
total = a[0] * a[1] * a[2]
for _ in range(a[3]):
    b = get_list()
    minus = (abs(b[0]-b[3])+1) * (abs(b[1]-b[4])+1) * (1+abs(b[2]-b[5]))
    print(total - minus)
