"""
    http://codeta.ml/contest/13/problem/hw402
    016 Pidgey vs 006 Charizard
"""
import requests
from bs4 import BeautifulSoup


class Poke:
    """
    属性(变数):
    name:名字
    hpMax:最大血量(基本耐力)
    hpCurrent:现存血量
    baseAttack:基本攻击
    baseDefense:基本防御

    方法(函式):
    attack(对手的Pokemon物件):攻击对手
    showInfo():显示此Pokemon内相关资讯
    """
    def __init__(self, num, name):
        url = "http://www.otaku-hk.com/pkmgo/en/pokemon/" + num + "/" + name
        r = requests.get(url)
        soup = BeautifulSoup(r.text, "html.parser")
        trs = soup.find("table").find_all("tr")
        self.name = name
        self.hpMax = int(trs[7].find_all("td")[1].text)
        self.hpCurrent = self.hpMax
        self.baseAttack = int(trs[8].find_all("td")[1].text)
        self.baseDefense = int(trs[9].find_all("td")[1].text)

    def attack(self, opponent):
        hurt = int(self.baseAttack / opponent.baseDefense * self.hpMax / 5)
        print("%s Attack %s %d Points." % (self.name, opponent.name, hurt))
        if opponent.hpCurrent > hurt:
            opponent.hpCurrent -= hurt
        else:
            opponent.hpCurrent = 0

    def show_info(self):
        print("Name: %s, HP: %d/%d" % (self.name, self.hpCurrent, self.hpMax))


if __name__ == '__main__':
    a = input()
    b = a.split()
    p1 = Poke(b[0], b[1])
    p2 = Poke(b[3], b[4])
    flag = False
    while p1.hpCurrent * p2.hpCurrent != 0:
        if flag:
            p2.attack(p1)
            flag = False
        else:
            p1.attack(p2)
            flag = True
        p1.show_info()
        p2.show_info()
    if p1.hpCurrent == 0:
        print("%s Win, %s Lose." % (p2.name, p1.name))
    else:
        print("%s Win, %s Lose." % (p1.name, p2.name))