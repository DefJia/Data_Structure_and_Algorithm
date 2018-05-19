import random

fo = open("data.in.txt", "r+")
num = 1000
fo.seek(0, 2)
fo.write(str(num)+'\n')
for i in range(1000):
    a = int(random.random() * 4) + 3
    fo.seek(0, 2)
    fo.write(str(a)+'\n')
    pp = ''
    for ii in range(a):
        b = int(random.random() * 5) + 1
        pp += str(b) + ' '
    fo.seek(0, 2)
    fo.write(pp+'\n')