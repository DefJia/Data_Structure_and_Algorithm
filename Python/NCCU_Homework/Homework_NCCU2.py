"""
    http://codeta.ml/contest/10/problem/hw302
"""
import datetime


def convert(s):
    t = s[:-6]
    flag = s[:-5]
    diff = s[-4:]
    hour = int(diff[:2])
    minute = int(diff[2:])
    so = datetime.datetime.strptime(t, "%a %d %b %Y %H:%M:%S")
    if flag == '+':
        so -= datetime.timedelta(hours=hour, minutes=minute)
    else:
        so += datetime.timedelta(hours=hour, minutes=minute)
    return so

def cal(a, b):
    res = b - a
    if(res.days/7 >= 1):
        q = int(res.days/7)
        print("%d week" % q, end='')
    elif(res.days != 0):
        q = res.days
        print("%d day" % q, end='')
    elif (res.seconds/3600 >= 1):
        q = int(res.seconds/3600)
        print("%d hour" % q, end='')
    elif (res.seconds/60 >= 1):
        q = int(res.seconds/60)
        print("%d minute" % q, end='')
    # elif (res.seconds != 0):
    else:
        q = res.seconds
        print("%d second" % q, end='')
    if q > 1:
        print('s', end='')
    print(' ago')
    return 0

if __name__ == '__main__':
    n = int(input())
    while(n):
        n -= 1
        a = convert(input())
        b = convert(input())
        cal(a, b)

