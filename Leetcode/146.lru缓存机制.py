#
# @lc app=leetcode.cn id=146 lang=python3
#
# [146] LRU缓存机制
#
# https://leetcode-cn.com/problems/lru-cache/description/
#
# algorithms
# Medium (46.56%)
# Likes:    471
# Dislikes: 0
# Total Accepted:    42K
# Total Submissions: 90.2K
# Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +'[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
#
# 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
# 
# 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
# 写入数据 put(key, value) -
# 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
# 
# 进阶:
# 
# 你是否可以在 O(1) 时间复杂度内完成这两种操作？
# 
# 示例:
# 
# LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
# 
# cache.put(1, 1);
# cache.put(2, 2);
# cache.get(1);       # 返回  1
# cache.put(3, 3);    # 该操作会使得密钥 2 作废
# cache.get(2);       # 返回 -1 (未找到)
# cache.put(4, 4);    # 该操作会使得密钥 1 作废
# cache.get(1);       # 返回 -1 (未找到)
# cache.get(3);       # 返回  3
# cache.get(4);       # 返回  4
# 
# 
#

# @lc code=start
class Node:
    def __init__(self, key, val):
        self.val = val
        self.key = key
        self.front = None
        self.back = None


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cnt = 0
        self.head = Node(0, -1)
        self.tail = Node(0, -1)
        self.head.back = self.tail
        self.tail.front = self.head
        self.data = dict()    

    def get(self, key: int) -> int:
        if key in self.data.keys():
            cur = self.data[key]
            self.delete(cur)
            self.insert(cur)
            print(cur.val)
            return cur.val
        else:
            print(-1)
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.data.keys():
            self.data[key].val = value
            cur = self.data[key]
            self.delete(cur)
            self.insert(cur)
        elif self.cnt < self.capacity:
            cur = Node(key, value)
            self.data[key] = cur 
            self.cnt += 1
            self.insert(cur) 
        else:
            del self.data[self.head.back.key]
            cur = Node(key, value)
            self.data[key] = cur
            self.delete(self.head.back)
            self.insert(cur)

    def insert(self, cur):
        self.tail.front.back = cur
        cur.front = self.tail.front
        cur.back = self.tail
        self.tail.front = cur
    
    def delete(self, cur):
        cur.front.back = cur.back
        cur.back.front = cur.front        
        

if __name__ == "__main__":
    actions = ["LRUCache","put","put","get","get","put","get","get","get"]
    nums = [[2],[2,1],[3,2],[3],[2],[4,3],[2],[3],[4]]
    cache = LRUCache(nums[0][0])
    for i in range(1, len(actions)):
        if actions[i] == 'get':
            cache.get(nums[i][0])
        else:
            cache.put(nums[i][0], nums[i][1])

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

