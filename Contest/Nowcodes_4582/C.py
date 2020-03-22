if __name__ == "__main__":
    x = get(0, 1)
    z = input()
    y = get(0, 1)
    data = dict()
    data2 =dict()
    rank = list()
    n = 1
    for i in x:
        for j in i[0]:
            data[j] = n
        n += len(i[0])
    n = 1
    for i in y:
        for j in i[0]:
            if j in data.keys():
                data2[j] = (data[j] + n) / 2
                del data[j]
            else:
                data[j] = -n
        n += len(i[0])
    a = sorted(data2.items(), key = lambda kv:(kv[1], kv[0]))
    for i in a:
        for j in x+y:
            if i[0] in j[0]:
                for k in j[0]:
                    if k in data.keys():
                        if k in data2.keys():
                            if data2[k] == i[1]:
                                pass
                            else:
                                del data[k]
                                del data2[k]
                        else:
                            data2[k] = i[1]
    t = list()
    for i in data.keys():
        if i in data2.keys():
            t.append(i)
    for i in t:
        del data[i]
    a = sorted(data2.items(), key = lambda kv:(kv[1], kv[0]))
    data3 = dict()
    for i in a:
        data3[i[0]] = i[1]
    tmp = list()
    tmp2 = list()
    for i in data:
        flag = 0
        c = x if data[i] > 0 else y
        xiao = 101; da = 0
        for j in c:
            if i in j[0]:
                flag = 1
            elif flag == 0:
                for k in j[0]:
                    if k in data3:
                        da = max(data3[k], da)
            else:
                for k in j[0]:
                    if k in data3:
                        xiao = min(data3[k], xiao)
                    if xiao <= da:
                        # 不能排
                        flag = -1
                        tmp.append(i)
                        break
            if flag < 0:
                break
        if flag >= 0:
            # 在a中找位置 负数
            for j in range(len(a)-1):
                if a[j][1] == da and a[j+1][1] == xiao:
                    tmp2.append(((a[j][1],a[j+1][1]), (i, data[i])))
                    break
                if xiao == 101:
                    tmp2.append((101, (i, data[i])))
                    break
                elif da == 0:
                    tmp2.append((0, (i, data[i])))
                    break
    for i in tmp:
        del data[i]

    res = list()
    t = list()
    for i in tmp2:
        if i[0] == 0:
            t.append((i[1][0], abs(i[1][1])))
    b = sorted(t, key = lambda kv:(kv[1], kv[0]))
    tmp2 = [i for i in tmp2 if i[0] != 0]
    cur = b[0][1]
    res.append([])
    for i in b:
        if i[1] == cur:
            res[-1].append(i[0])
        else:
            cur = i[1]
            res.append([i[0]])

    cur = a[0][1]
    res.append([])
    for i in range(len(a)):
        if a[i][1] == cur:
            res[-1].append(a[i][0])
        else:
            res.append([])
            res[-1].append(a[i][0])
            cur = a[i][1]
        if i != len(a)-1:
            tmp3 = list()
            for j in tmp2:
                if j[0] == (a[i][1], a[i+1][1]):
                    tmp3.append((j[1][0], abs(j[1][1])))
            if tmp3:
                b = sorted(tmp3, key = lambda kv:(kv[1], kv[0]))
                cur_ = b[0][1]
                res.append([])
                for i in b:
                    if i[1] == cur_:
                        res[-1].append(i[0])
                    else:
                        cur_ = i[1]
                        res.append([i[0]])

    t = list()
    for i in tmp2:
        if i[0] == 101:
            t.append((i[1][0], abs(i[1][1])))
    b = sorted(t, key = lambda kv:(kv[1], kv[0]))
    cur = b[0][1]
    res.append([])
    for i in b:
        if i[1] == cur:
            res[-1].append(i[0])
        else:
            cur = i[1]
            res.append([i[0]])

    for i in res:
        print(*i)
