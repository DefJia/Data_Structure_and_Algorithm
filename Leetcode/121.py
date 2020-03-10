class Solution:
    def maxProfit(self, prices):
        if prices:
            # 注意给定数组为空的情况
            history_min = prices[0]
            res = [0] * len(prices)
            for i in range(1, len(prices)):
                history_min = min(history_min, prices[i])
                res[i] = prices[i] - history_min
            return max(res)
        else:
            return 0


if __name__ == "__main__":
    in_ = [7,1,5,3,6,4]
    a = Solution()
    b = a.maxProfit(in_)
    print(b)
    