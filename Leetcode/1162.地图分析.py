#
# @lc app=leetcode.cn id=1162 lang=python3
#
# [1162] 地图分析
#

# @lc code=start
class Solution:
    @staticmethod
    def if_bank(grid, i, j):
        l = len(grid)
        flag = True
        if i != 0:
            flag = flag & grid[i-1][j] == 1
        if i != l-1:
            flag = flag & grid[i+1][j] == 1
        if j != 0:
            flag = flag & grid[i][j-1] == 1
        if j != l-1:
            flag = flag & grid[i][j+1] == 1
        return not flag

    @staticmethod
    def set(grid, i, j):
        l = len(grid)
        rec = list()
        if i != 0 and grid[i-1][j] == 0:
            grid[i-1][j] = 1; rec.append((i-1, j))
        if i != l-1 and grid[i+1][j] == 0:
            grid[i+1][j] = 1; rec.append((i+1, j))
        if j != 0 and grid[i][j-1] == 0:
            grid[i][j-1] = 1; rec.append((i, j-1))
        if j != l-1 and grid[i][j+1] == 0:
            grid[i][j+1] = 1; rec.append((i, j+1))
        return rec

    def maxDistance(self, grid):
        ground_num = cnt = 0
        rest = list()  # 剩余海边
        l = len(grid)
        for i in range(l):
            for j in range(l):
                if grid[i][j] == 1:
                    ground_num += 1
                    if self.if_bank(grid, i, j):
                        rest.append((i, j))
        if ground_num in (l**2, 0):
            return -1
        while ground_num < l**2:
            tmp = list()
            for (i, j) in rest:
                res = self.set(grid, i, j)
                ground_num += len(res)
                for (p, q) in res:
                    if self.if_bank(grid, p, q):
                        tmp.append((p, q))
            rest = tmp.copy()
            cnt += 1
        return cnt


if __name__ == "__main__":
    grid = [[1,0,1],[0,0,0],[1,0,1]]
    a = Solution()
    print(a.maxDistance(grid))

# @lc code=end

