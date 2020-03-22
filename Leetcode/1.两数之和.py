#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = dict()
        for i in range(len(nums)):
            if (target - nums[i]) in res:
                a, b = i, res[target - nums[i]]
                break
            else:
                res[nums[i]] = i
        return [a, b]

# @lc code=end

