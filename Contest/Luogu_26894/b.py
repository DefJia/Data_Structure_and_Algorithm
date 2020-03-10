a = input().split(' ')

b = int(a[0])
c= int(a[1])

cnt = int(b/c)
sum = (1+cnt)*cnt/2 * c
q = sum / cnt if cnt != 0 else 0

p = (1+b)*b/2 - sum
p = p / (b-cnt) if b != cnt else 0

print('%.1f %.1f' % (q, p))

# https://www.luogu.com.cn/contest/26894

