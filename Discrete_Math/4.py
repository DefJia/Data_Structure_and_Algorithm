if __name__ == '__main__':
    n = int(input())
    in_ = [0 for i in range(n)]
    out_ = [0 for i in range(n)]
    for i in range(n):
        tmp = input().split()
        for ii in range(n):
            if tmp[ii] == '1':
                out_[i] += 1
                in_[ii] += 1
    for i in range(n):
        print(format("%d %d") % (out_[i], in_[i]))
