import random
a = 20  # quantity of Vertexes
for i in range(a):
    print(chr(97 + i))
print('*')
for i in range(a):
    for ii in range(i+1, a):
        if random.random() > 0.8:
            print("%d,%d" % (i, ii))
print("-1, -1")