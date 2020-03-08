a = int(input())
lst = list()
index_0 = list()
cnt_neg = 0
remain_index = list()
for i in range(1, a+1):
    remain_index.append(i)
max_neg = (-1, -1000000001)
num = input().split()
for i in range(a):
    num.append(int(num[0]))
    del num[0]
for i in range(1, a+1):
    if num[i-1] < 0:
        cnt_neg += 1
        if num[i-1] > max_neg[1]:
            max_neg = (i, num[i-1])
    elif num[i-1] == 0:
        index_0.append(i)
    # lst.append(num)
res = list()
if len(index_0) > 0:
    remain_index -= index_0
    for i in range(len(index_0)-1):
        res.append((1, index_0[0], index_0[1]))
        del index_0[0]
    remain_index += index_0
    if cnt_neg % 2 == 1:
        res.append((1, max_neg[0], index_0[0]))
        remain_index -= [max_neg[0]]
    if len(remain_index) == 1:
        pass
    else:
        res.append((2, index_0[0]))
        remain_index -= index_0
    for i in range(len(remain_index)-1):
        res.append((1, remain_index[i], remain_index[i+1]))
else:
    if cnt_neg % 2 == 1:
        remain_index -= [max_neg[0]]
        res.append((2, max_neg[0]))
    for i in range(len(remain_index)-1):
        res.append((1, remain_index[i], remain_index[i+1]))
for elem in res:
    if len(elem) == 3:
        print("%d %d %d" % (elem[0], elem[1], elem[2]))
    else:
        print("%d %d" % (elem[0], elem[1]))