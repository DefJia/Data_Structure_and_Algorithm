# 公历纪年法中，能被4整除的大多是闰年，但能被100整除而不能被400整除的年份不是闰年， 能被3200整除的也不是闰年，如1900年是平年，2000年是闰年，3200年不是闰年。

def get_list():
    a = input().split(' ')
    b = []
    for i in a:
        b.append(int(i))
    return b

def is_run(id):
    if id % 4 == 0:
        if id % 100 == 0 and id % 400 != 0:
            return 0
        else:
            return 1
    else:
        return 0

a = get_list()
n = 0
p = list()
for i in range(a[0], a[1]+1):
    q = is_run(i)
    n += q
    if q:
        p.append(i)

print(n)
print(' '.join(str(i) for i in p))