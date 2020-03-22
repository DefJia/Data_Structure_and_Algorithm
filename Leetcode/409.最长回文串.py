#
# @lc app=leetcode.cn id=409 lang=python3
#
# [409] 最长回文串
#

# @lc code=start
class Solution:
    @staticmethod
    def judge(a):
        if 65 <= ord(a) <= 90:
            return ord(a) - 65
        else:
            return ord(a) - 97 + 26
    def longestPalindrome(self, s: str) -> int:
        hash = [0 for i in range(52)]
        for i in s:
            hash[self.judge(i)] += 1 
        flag = 0
        cnt = 0
        for i in hash:
            cnt += (i // 2) * 2
            flag += i % 2
        flag = 1 if flag > 0 else 0
        return cnt + flag


if __name__ == "__main__":
    a = Solution().longestPalindrome('adsca')
    print(a)

        
# @lc code=end

