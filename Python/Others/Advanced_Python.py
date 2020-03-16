# make funtion as parameter
import math
def add(x, y, f):
    return f(x) + f(y)
print (add(25, 9, math.sqrt))

# map()
def f(s):
    return s.capitalize()
print (map(f, ['adam', 'LISA', 'barT']))

# reduce()
from functools import reduce
def prod(x, y):
    return x*y
print (reduce(prod, [2, 4, 5, 7, 12]))

# filter()
def is_sqr(x):
    return int(math.sqrt(x))**2 == x
print (filter(is_sqr, range(1,101)))

# user-defined sorted()
'''
def c(s1, s2):
    q = s1.lower(); w = s2.lower()
    if q>w: return 1
    elif q<w: return -1
    else: return 0
print (sorted(['bob', 'about', 'Zoo', 'Credit'], c))
'''

# return a function
def calc_prod(lst):
    def q(x, y):
        return x*y
    def a():
        return reduce(q, lst)
    return a
f = calc_prod([1, 2, 3, 4])
print (f())

# 闭包
def count():
    fs = []
    for i in range(1, 4):
        def f(j):
            def g():
                return j**2
            return g
        fs.append(f(i))
    return fs
f1, f2, f3 = count()
print (f1(), f2(), f3())

# lambda
print (filter(lambda s: s and len(s.strip())>0, ['test', None, '', 'str', ' ', 'end']))

# decorator w/o parameter
import time
def performance(f):
    def fn(*args, **kw):
        t1 = time.time()
        r = f(*args, **kw)
        t2 = time.time()
        print ('call %s() in %fs' % (f.__name__, (t2 - t1)))
        return r
    return fn
@performance
def factorial(n):
    return reduce(lambda x,y: x*y, range(1, n+1))
factorial(10)

# decorator with parameters

# 偏函数
import functools
# sorted_ignore_case = functools.partial(sorted, lambda s1, s2: cmp(s1.upper(), s2.upper()))
# print(sorted_ignore_case(['bob', 'about', 'Zoo', 'Credit']))

# sorted
# sorted(L1, lambda p1, p2: cmp(p1.name, p2.name))

class Person:
    __count = 0
    count = 0
    @classmethod
    def cnt(cls):
        return cls.__count
    def __init__(self, name):
        self.name = name
        Person.__count += 1
        Person.count += 1
        # 类实例
        self.get_grade = lambda: 90
print(Person.cnt(), Person.count)
a = Person('Alice')
print(a.get_grade)
print(a.get_grade())
b = Person('Bob')
print(Person.cnt(), Person.count)
print(a.cnt(), a.count)
print(b.cnt(), b.count)

class Person():
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender
    def whoIAm(self):
        return self.name
class Teacher(Person):
    def __init__(self, name, gender, course):
        super(Teacher, self).__init__(name, gender)
        # 继承
        self.course = course
t = Teacher('Alice', 'Female', 'English')
print(isinstance(t, Person))
print(isinstance(t, Teacher))
print(isinstance(t, object))
print(t.whoIAm())

# 定义四则运算
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)
class Rational(object):
    def __init__(self, p, q):
        self.p = p
        self.q = q
    def __add__(self, r):
        return Rational(self.p * r.q + self.q * r.p, self.q * r.q)
    def __sub__(self, r):
        return Rational(self.p * r.q - self.q * r.p, self.q * r.q)
    def __mul__(self, r):
        return Rational(self.p * r.p, self.q * r.q)
    def __div__(self, r):
        return Rational(self.p*r.q, self.q*r.p)
    def __str__(self):
        g = gcd(self.p, self.q)
        return '%s/%s' % (self.p / g, self.q / g)
    __repr__ = __str__
r1 = Rational(1, 2)
r2 = Rational(1, 4)
print (r1 + r2, r1 - r2, r1 * r2)

# proper
class Student(object):
    def __init__(self, name, score):
        self.name = name
        self.__score = score
    @property
    def score(self):
        return self.__score
    @score.setter
    def score(self, score):
        if score < 0 or score > 100:
            raise ValueError('invalid score')
        self.__score = score
    @property
    def grade(self):
        if self.score < 60:
            return 'C'
        if self.score < 80:
            return 'B'
        return 'A'
s = Student('Bob', 59)
print (s.grade)
s.score = 60
print (s.grade)
s.score = 99
print (s.grade)

# Fib & __call__
class Fib(object):
    def __call__(self, num):
        a,b,L = 0,1,[]
        for i in range(num):
            L.append(a)
            a, b = b, a+b
        return L
f = Fib()
print (f(10))

# decorator ↓
# https://www.imooc.com/video/6064
