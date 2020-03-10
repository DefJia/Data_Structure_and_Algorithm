def get(*arg):
    if arg[0] == 0:
        cnt = int(input())
        flag = 1
    else:
        cnt = 1
        flag = 0
    lst = list()
    for i in range(cnt):
        lst2 = list()
        for ii in range(len(arg)-flag):
            if arg[ii+flag] == 1:
                t = input().split()
                tmp = list()
                for iii in t:
                    tmp.append(int(iii))
            elif arg[ii+flag] == 2:
                tmp = input().split()
            else:
                tmp = input()
            lst2.append(tmp)
        lst.append(lst2)
    return lst


def find(s, k, n):
    # s-字符串 k-位置 n-第几次
    l = len(s)
    if (k + n -2 <= l - 1):
        # 没有用到k前面的序列
        return s[k+n-2]
    else:
        flag = 0 if (l-k+1)%2 == 0 else 1
        # 0-正不翻转 1-负翻转
        if not flag:
            return s[k+n-2-l]
        else:
            return s[l-n]

def gene(s, k):
    l = len(s)
    flag = 0 if (l-k+1)%2 == 0 else 1
    if flag:  # negetive
        f = s[k-1:] + s[:k-1][::-1]
    else:
        f = s[k-1:] + s[:k-1]
    return f
    

if __name__ == "__main__":
    a = get(0, 1, 3)
    for i in a:
        s = i[1]
        l = i[0][0]
        ans = dict()
        for i in range(l):
            ans[i] = s[i]
        cnt = 0
        flag = 0
        while cnt < l:
            cnt += 1  # 轮次
            min = 200
            for i in ans:
                if ord(ans[i]) < min:
                    min = ord(ans[i])
            # find min
            d = list()
            for i in ans:
                if ord(ans[i]) > min:
                    d.append(i)
                else:
                    ans[i] = find(s, i+1, cnt+1)
            for i in d:
                ans.pop(i)
            if len(ans) == 1:
                k = list(ans.keys())[0]+1
                flag = 1
                break
        if cnt == l and flag == 0:
            k = sorted(list(ans.keys()))[0]+1
        final_s = gene(s, k)
        print(final_s)
        print(k)

