def test(q):
   if q == 1: return 1
   if q == 2: return 3
   elif q % 2 == 1: return 2 * q - 1
   elif q % 2 == 0: return test(q/2 + 1) * 2 -2

a = input()
while not str(a) == '':
    # if not a: break
    print(int(test(int(a))))
    a = input()
