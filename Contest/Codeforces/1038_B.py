a = int(input())
if a <= 2:
    print('No')
else:
    print('Yes')
    print(2, end=' ')
    print('1 %d' % a)
    print(a-2, end=' ')
    for i in range(2, a):
        print(i, end='')
        if not i == a - 1:
            print(' ', end='')
    print('')