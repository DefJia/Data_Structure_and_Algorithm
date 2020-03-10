import requests
import json


class DoubanSpider:
    def __init__(self):  # URL里面有的参数是不需要的。可以删掉。 callback等  https://m.douban.com/rexxar/api/v2/subject_collection/tv_domestic/items?os=windows%207&for_mobile=1&callback=jsonp1&start=0&count=18&loc_id=108288&_=1554601091490
        self.url_temp = 'https://m.douban.com/rexxar/api/v2/subject_collection/tv_domestic/items?start={}&count=18&loc_id=108288'
        self.headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.86 Safari/537.36'}

        # 定义获取url的方法

    def parse_url(self, url):  # 发送get请求(请求方式看请求头来判断，获取响应
        print(url)
        response = requests.post(url, headers=self.headers)
        return response.content.decode()

    def get_content_list(self, json_str):
        dict_ret = json.loads(json_str)  # 把接收过来的json_str变成字典
        content_list = dict_ret['subject_collection_items']  # subject_collection_items 键里面的值是个列表，18个电视剧信息
        return content_list

    def save_content_list(self, content_list):
        with open('douban.txt', 'a', encoding='utf-8') as f:
            for content in content_list:
                f.write(json.dumps(content, ensure_ascii=False))  # ensure_ascii=False中文显示出来
                f.write('\n')  # 一行写一条
        print("保存成功")

    def run(self):  # 实现主要逻辑
        num = 0  # 页码数
        while True:
            # 1.构造strat_url
            url = self.url_temp.format(num)

            # 2.发送请求，获取响应
            json_str = self.parse_url(url)  # 接收一下定义的 parse_url 的返回值，得到的是json字符串
            # 3.提取数据
            content_list = self.get_content_list(json_str)  # 接收一下定义的 get_content_list 的返回值
            # 4.保存
            self.save_content_list(content_list)
            # if len(content_list) < 18:   # 如果拿到的列表小于18行，则说明后面没有了。
            #     break
            # 5.构造下一页url地址，不断循环以上步骤
            num += 18


if __name__ == '__main__':
    douban_spider = DoubanSpider()
    douban_spider.run()

    # 5.构造下一页url地址，不断循环以上步骤
    # num+=18
    # url = self.url_temp.format(num)
    # json_str = self.parse_url(url)
    # content_list = self.get_content_list(json_str)
    # self.save_content_list(content_list)
    # num+=18
    # url = self.url_temp.format(num)
    # json_str = self.parse_url(url)
    # content_list = self.get_content_list(json_str)
    # self.save_content_list(content_list)
    # num+=18
    # url = self.url_temp.format(num)
    # json_str = self.parse_url(url)
    # content_list = self.get_content_list(json_str)
    # self.save_content_list(content_list)
