a = input()
i = 0
cnt = 0
while(i < len(a)-2):
    if a[i] == 'U' and a[i+1:i+3] in ('AA', 'AG', 'GA'):
        i += 2
        cnt += 1
    i += 1
print(cnt)

