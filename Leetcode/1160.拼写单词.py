#
# @lc app=leetcode.cn id=1160 lang=python3
#
# [1160] 拼写单词
#

# @lc code=start
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        hash = [0 for i in range(26)]
        for i in chars:
            hash[ord(i)-97] += 1
        cnt = 0
        for i in words:
            tmp = hash.copy()
            flag = 0
            for j in i:
                if tmp[ord(j)-97] > 0:
                    tmp[ord(j) - 97] -= 1
                else:
                    flag = 1
                    break
            if not flag:
                cnt += len(i)
        return cnt
        
# @lc code=end

