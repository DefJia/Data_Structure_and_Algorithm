#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个有序数组的中位数
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        a = b = 0
        c = list()
        while a != len(nums1) and b != len(nums2):
            if nums1[a] <= nums2[b]:
                c.append(nums1[a])
                a+=1
            else:
                c.append(nums2[b])
                b+=1
        if a == len(nums1):
            c += nums2[b:]
        elif b == len(nums2):
            c+= nums1[a:]
        if len(c) % 2:
            return float(c[len(c)//2])
        else:
            return (c[len(c)//2]+c[len(c)//2-1])/2

if __name__ == "__main__":
    a = [1,3,5,7]
    b = [2,4,6,8]
    c = Solution()
    c = c.findMedianSortedArrays(a, b)
    print(c)

# @lc code=end

