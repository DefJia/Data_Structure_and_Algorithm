"""
    http://codeta.ml/contest/10/problem/hw305
"""
from collections import OrderedDict
if __name__ == '__main__':
    place = OrderedDict()
    while True:
        try:
            a = input()
            b = a.split()
            if not b[2] in place:
                place[b[2]] = {}
            if not b[0] in place[b[2]]:
                place[b[2]][b[0]] = int(b[1])
            else:
                place[b[2]][b[0]] += int(b[1])
        except:
            break
    for elem in place:
        print("%s:" % elem, end='')
        while len(place[elem]) != 0:
            x = max(place[elem].items(), key=lambda x: x[1])
            print("%s %s" % (x[0], x[1]), end='')
            if len(place[elem]) != 1:
                print(',', end='')
            else:
                print('\n', end='')
            del place[elem][x[0]]



