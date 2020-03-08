a = int(input())
q1 = [100001]
q2 = [100001]
q3 = [100001]
q4 = [100001]
q5 = [100001]
q6 = [100001]
q7 = [100001]
for i in range(a):
    b = input().split()
    price = int(b[0])
    vitamins = b[1]
    if len(vitamins) == 3: q7.append(price)
    elif len(vitamins) == 2:
        if not 'A' in vitamins: q4.append(price)
        elif not 'B' in vitamins: q5.append(price)
        else: q6.append(price)
    else:
        if vitamins == 'A': q1.append(price)
        elif vitamins == 'B':q2.append(price)
        else: q3.append(price)
    a1 = min(q1)
    a2 = min(q2)
    a3 = min(q3)
    a4 = min(q4)
    a5 = min(q5)
    a6 = min(q6)
    a7 = min(q7)
tmp = min(a7, a6+a5, a4+a5, a4+a6, a1+a4, a2+a5, a3+a6, a1+a2+a3)
if tmp == 100001: tmp = -1
print(tmp)
