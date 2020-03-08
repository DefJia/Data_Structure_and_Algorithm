def solution(s, l):
    a = [0 for i in range(26)]
    num = 1
    for i in range(len(s)):
        q = len(s)-1 - i
        if num <= len(l):
            while(l[num-1] == q+1):
                num += 1
                if num > len(l):
                    break
        a[ord(s[q])-97] += num
    return a


if __name__ == "__main__":
    a = int(input())
    for i in range(a):
        b = input()
        s = input()
        l = input().split(' ')
        for i in range(len(l)):
            l[i] = int(l[i])
        l.sort(reverse=True)
        q = solution(s, l)
        p = ''
        for i in q:
            p += str(i) + ' '
        print(p[:-1])
