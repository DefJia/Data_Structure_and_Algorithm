def get_list():
    return map(lambda x:int(x), input().split()) 

# 1. num+num*cnt
# 2. cnt

# 若有打头 0
# 空格数字 1
# 空格字符串 2 
# 纯字符串 3

def get(*arg):
    if arg[0] == 0:
        cnt = int(input())
        flag = 1
    else:
        cnt = 1
        flag = 0
    lst = list()
    for i in range(cnt):
        lst2 = list()
        for ii in range(len(arg)-flag):
            if arg[ii+flag] == 1:
                t = input().split()
                tmp = list()
                for iii in t:
                    tmp.append(int(iii))
            elif arg[ii+flag] == 2:
                tmp = input().split()
            else:
                tmp = input()
            lst2.append(tmp)
        lst.append(lst2)
    return lst


if __name__ == "__main__":
    a = get(0, 1, 2)
    b = 1