class Solution:
    def smallerNumbersThanCurrent(self, nums):
        hash = [0 for i in range(101)]
        for i in nums:
            hash[i] += 1
        hash2 = [0 for i in range(101)]
        for i in range(1, 101):
            hash2[i] = hash2[i-1] + hash[i-1]
        for i in range(len(nums)):
            nums[i] = hash2[nums[i]]
        return nums


if __name__ == "__main__":
    nums = [8,1,2,2,3]
    a = Solution()
    a = a.smallerNumbersThanCurrent(nums)
    print(a)
