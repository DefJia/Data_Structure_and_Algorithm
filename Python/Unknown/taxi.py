class Main:
    def __init__(self):
        origin_file = 'taxi.csv'
        target_file = 'taxi_res2.txt'
        self.f = open(origin_file, 'r+')
        self.r = open(target_file, 'w+')
        self.data = list()
        self.triggers = list()

    def read(self):
        lines = self.f.read().split('\n')
        for line in lines:
            tmp = line.split(',')
            self.data.append(tmp)

    def find_trigger(self):
        flag = 0
        cnt = 0
        for elem in self.data:
            if int(elem[-3]) != flag:
                flag = int(elem[-3])
                self.triggers.append(cnt)
            cnt += 1

    def output(self):
        string = ''
        last_trigger = 0
        taxi_no = self.data[0][2]
        cnt = 0
        for trigger in self.triggers:
            tmp = [list(), list(), list(), list(), list()]
            cnt += 1
            print(last_trigger)
            for i in range(last_trigger, trigger):
                elem = self.data[i]
                flag = int(elem[-3])
                tmp[0].append(elem[3])
                tmp[1].append(elem[4])
                tmp[2].append(elem[5])
                tmp[3].append(elem[8])
                tmp[4].append(elem[9])
            string_middle = ''
            for sub_lst in tmp:
                for elem in sub_lst:
                    string_middle += elem + ','
                string_middle = string_middle[:-1] + '|'
            string_single = format('%s|%s|%d' % (taxi_no, string_middle[:-1], flag))
            string += string_single + '\n'
            last_trigger = trigger
            if cnt % 100 == 0:
                self.r.write(string)
                string = ''


if __name__ == '__main__':
    cur = Main()
    cur.read()
    cur.find_trigger()
    cur.output()
    a = 2