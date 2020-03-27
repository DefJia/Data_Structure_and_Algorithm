#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#

# @lc code=start
class Solution:
    def letterCombinations(self, digits):
        data = ['acb', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        res = []
        def backtrack(already, n):
            if n >= len(digits):
                if n:
                    res.append(already)
            else:
                for i in data[int(digits[n])-2]:
                    backtrack(already+i, n+1)
        backtrack('', 0)
        return res

if __name__ == "__main__":
    a = ''
    b = Solution().letterCombinations(a)
    print(b)



# @lc code=end

