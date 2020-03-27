#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#

# @lc code=start
class Solution:
    def subsets(self, nums):
        res = []
        def backtracking(tmp, n):
            if n == len(nums):
                res.append(list(tmp))
            else:
                backtracking(tmp, n+1)
                tmp += (nums[n],)
                backtracking(tmp, n+1)
        backtracking((), 0)
        return res

if __name__ == "__main__":
    a = [1,2,3]
    b = Solution().subsets(a)
    print(b)

# @lc code=end

