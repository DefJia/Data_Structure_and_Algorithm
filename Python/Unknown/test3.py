if __name__ == '__main__':
    a = input().split()
    nv = int(a[0])
    ne = int(a[1])
    graph = [list() for i in range(nv+1)]
    for i in range(ne):
        t = input().split()
        graph[int(t[0])].append(int(t[1]))
        graph[int(t[1])].append(int(t[0]))
    for i in graph:
        i.sort()
    # Construction
    hash = [0 for i in range(nv+1)]  # able to but haven't to
    # hhh
    record = list()
    record.append(1)  # 1. record
    hash[1] = 2  # 2. change status
    min_ = graph[1][0]  # 3. confirm minimal
    for i in graph[1]:
        if hash[i] == 0:
            hash[i] = 1
    while len(record) != nv:
        # confirm min_ as the target
        record.append(min_)
        hash[min_] = 2
        for i in graph[min_]:
            if hash[i] == 0:
                hash[i] = 1
        j = 0
        flag = 0
        while flag == 0 and j < len(graph[min_]):
            if hash[graph[min_][j]] == 1 and graph[min_][j] < min_:
                flag = 1
                min_ = graph[min_][j]
            j += 1
        if flag == 0:
            j = min_ + 1
            while j <= nv and hash[j] != 1:
                j += 1
            min_ = j
    for i in record:
        print(i, end=' ')

