if __name__ == "__main__":
    w = get(0, 1, 3, 3)
    for i in w:
        a = i[1]
        b = i[2]
        n = i[0][0]
        # c = [0, 0, 0,0] # cg gc au ua
        c = dict()
        for p in 'CGAU':
            c[p] = 0
        cnt = 0
        for j in range(n):
            if (a[j], b[j]) not in [('A', 'U'), ('G', 'C'), ('U', 'A'), ('C', 'G')]:
                if a[j] == b[j]:
                    c[b[j]] += 1
                else:
                    cnt += 1
        cnt += max(c['A'], c['U']) + max(c['G'], c['C'])
        print(cnt)

