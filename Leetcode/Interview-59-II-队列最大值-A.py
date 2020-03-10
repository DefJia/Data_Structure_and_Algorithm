import queue
# 事实证明 用collections里的deque对象确实慢一些


class MaxQueue:

    def __init__(self):
        self.hash = [0] * 100001
        self.x = 0
        self.que = queue.deque()


    def max_value(self) -> int:
        if len(self.que):
            return self.x
        else:
            return -1

    def push_back(self, value: int) -> None:
        self.que.append(value)
        self.hash[value] += 1
        self.x = max(self.x, value)

    def pop_front(self) -> int:
        if len(self.que):
            a = self.que.popleft()
            self.hash[a] -= 1
            if len(self.que) and self.x == a and not self.hash[a]:
                for i in range(a):
                    if self.hash[a-1-i]:
                        self.x = a-1-i
                        break
            if not len(self.que):
                self.x = 0
            return a
        else:
            return -1



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()

