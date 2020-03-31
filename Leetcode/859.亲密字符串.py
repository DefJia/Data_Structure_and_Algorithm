#
# @lc app=leetcode.cn id=859 lang=python3
#
# [859] 亲密字符串
#
# https://leetcode-cn.com/problems/buddy-strings/description/
#
# algorithms
# Easy (28.89%)
# Likes:    80
# Dislikes: 0
# Total Accepted:    11.3K
# Total Submissions: 39.2K
# Testcase Example:  '"ab"\n"ba"'
#
# 给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false
# 。
# 
# 
# 
# 示例 1：
# 
# 输入： A = "ab", B = "ba"
# 输出： true
# 
# 
# 示例 2：
# 
# 输入： A = "ab", B = "ab"
# 输出： false
# 
# 
# 示例 3:
# 
# 输入： A = "aa", B = "aa"
# 输出： true
# 
# 
# 示例 4：
# 
# 输入： A = "aaaaaaabc", B = "aaaaaaacb"
# 输出： true
# 
# 
# 示例 5：
# 
# 输入： A = "", B = "aa"
# 输出： false
# 
# 
# 
# 
# 提示：
# 
# 
# 0 <= A.length <= 20000
# 0 <= B.length <= 20000
# A 和 B 仅由小写字母构成。
# 
# 
#

# @lc code=start
class Solution:
    def buddyStrings(self, a, b):
        if len(a) == len(b):
            lst = list()
            hash = [0 for i in range(26)]
            for i in range(len(a)):
                if a[i] == b[i]:
                    hash[ord(a[i])-97] += 1
                else:
                    lst.append((a[i], b[i]))
                    if len(lst) > 2:
                        return False
            if len(lst) == 0:
                for i in hash:
                    if i > 1:
                        return True
                return False
            elif len(lst) == 1:
                return False
            else:
                if lst[0][1] == lst[1][0] and lst[0][0] == lst[1][1]:
                    return True
                else:
                    return False
        else:
            return False


if __name__ == "__main__":
    a = Solution()
    A = "abcaa"; B = "abcbb"
    print(a.buddyStrings(A, B))
# @lc code=end

