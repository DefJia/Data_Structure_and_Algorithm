"""
    http://codeta.ml/contest/13/problem/hw401

2018/03/23 JPY 1000
2018/03/26 JPY 600
2018/04/25 EUR 120
2018/04/26 EUR 32
2018/05/02 USD 650
2018/05/03 USD 200

"""
import requests
from bs4 import BeautifulSoup


def crawl(date, currency):
    url = "http://rate.bot.com.tw/xrt/all/" + date
    r = requests.get(url)
    soup = BeautifulSoup(r.text, "html5lib")
    table = soup.find("tbody")
    tr = table.find_all("tr")
    for elem in tr:
        td = elem.find_all("td")
        a = td[0].text.split()
        if currency == a[1][1:-1]:
            return float(td[4].text)


if __name__ == '__main__':
    sum_ = 0
    while True:
        try:
            a = input()
            # print(a)
            b = a.split()
            c = b[0].split('/')
            date = c[0] + '-' + c[1] + '-' + c[2]
            price = crawl(date, b[1]) * float(b[2])
            sum_ += round(price)
        except:
            break
    print(sum_)