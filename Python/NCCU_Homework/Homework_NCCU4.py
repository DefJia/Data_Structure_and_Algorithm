"""
    http://codeta.ml/contest/10/problem/hw304
"""
from collections import OrderedDict
from fractions import Fraction
'''
def devide(a, b):
    quotient = ''
    a *= pow(10, 6)
    count = 0
    last =
    for i in range(20):
        quotient += str(int(a / b))
'''
if __name__ == '__main__':
    n = int(input())
    pts = OrderedDict()
    while n != 0:
        a = input().split()
        n -= 1
        pts[a[0]] = []
        for i in range(1, len(a)):
            x = a[i].split(':')
            time = int(x[0]) * 60 + float(x[1])
            pts[a[0]].append(time)
    print("%-5s%-7s%s" % ('rank', 'name', 'time'))
    hashh = OrderedDict()
    for elem in pts:
        w1 = sum(pts[elem]) * pow(10, 6)
        w2 = len(pts[elem])
        hashh[elem] = Fraction(int(w1), w2)
        # hashh[elem] = sum(pts[elem]) / len(pts[elem])
    order = 0
    same = 0
    winner = []
    last = 0
    for i in range(len(hashh)):
        x = max(hashh.items(), key=lambda x: x[1])
        del hashh[x[0]]
        if x[1] == last:
            same += 1
        else:
            order += same + 1
            same = 0
        last = x[1]
        if order == 1:
            winner.append(x[0])
        print("%-5d%-7s" % (order, x[0]), end='')
        for ii in range(len(pts[x[0]])):
            yi = max(pts[x[0]])
            pts[x[0]].remove(yi)
            print("%.2f" % yi, end='')
            if len(pts[x[0]]) == 0:
                print('')
            else:
                print(',', end='')
    print('')
    for i in range(len(winner)):
        print(winner[i], end='')
        if i == len(winner)-1:
            print('')
        else:
            print(',', end='')