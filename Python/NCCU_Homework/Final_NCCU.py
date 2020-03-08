import requests
from bs4 import BeautifulSoup


if __name__ == '__main__':
    a = input()
    a = a.split()
    b = "+".join(a)
    url = "https://www.imdb.com"
    url1 = url + "/find?q=" + b
    r = requests.get(url1)
    soup = BeautifulSoup(r.text, "html.parser")
    link = soup.find("td", class_="result_text").find("a").get("href")
    url2 = url + link
    r = requests.get(url2)
    soup = BeautifulSoup(r.text, "html.parser")
    pre_count = soup.find(id="filmo-head-producer")
    count = pre_count.text.split()[3][1:]
    pre_list = pre_count.next_sibling.next_sibling
    list = pre_list.find_all("div")
    print("%s credits" % count)
    for elem in list:
        try:
            year = elem.find("span").text
            title = elem.find("b").text
            href = url + elem.find("a").get("href")
            try:
                r = requests.get(href)
                a = r.text.split("ratingValue")
                if len(a) > 1:
                    print(a[1][2:5], end='-')
            except: pass
            print(title, end="")
            if len(year) != 3: print(",%s" % year[2:-1])
            else: print("")
        except: pass