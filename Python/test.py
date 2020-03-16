a = ['test', None, '', 'str', '  ', 'END']
b = map(lambda x:  x and len(x.strip()), a)
for i in b: print(i)