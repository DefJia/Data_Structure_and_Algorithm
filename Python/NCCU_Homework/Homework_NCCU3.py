"""
    http://codeta.ml/contest/10/problem/hw303
"""
import math


def convert(s):
    cmd = 'XYDULR'
    if s == 'B': return 1, 1
    if s == 'E': return 0, 0
    tmp = s.split()
    if len(tmp) == 2:
        if len(tmp[0]) == 1 and tmp[0] in cmd and tmp[1].isdigit():
            return tmp[0], int(tmp[1])
        if len(tmp[1]) == 1 and tmp[1] in cmd and tmp[0].isdigit():
            return tmp[1], int(tmp[0])
    return -1, -1

if __name__ == '__main__':
    a = input()
    c, n = convert(a)
    flag = 0
    while flag != -1:
        if c == 1:
            flag = 1
        if flag == 1:
            if c == 'X':
                x = n
                qx = x
            if c == 'Y':
                y = n
                qy = y
            if c == 'U':
                y += n
            if c == 'D':
                y -= n
            if c == 'L':
                x -= n
            if c == 'R':
                x += n
        a = input()
        c, n = convert(a)
        if c == 0 and flag == 1:
            flag = -1
    z = math.sqrt(abs(pow(x-qx, 2)+pow(y-qy, 2)))
    print("X %d\nY %d\nT %.3f\n" % (x, y, z))