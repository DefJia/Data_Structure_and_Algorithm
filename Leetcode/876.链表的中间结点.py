#
# @lc app=leetcode.cn id=876 lang=python3
#
# [876] 链表的中间结点
#

# @lc code=start
# Definition for singly-linked list. 

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        quick = slow = head
        while quick.next:
            quick = quick.next
            slow = slow.next
            if quick.next:
                quick = quick.next
        return slow
        
# @lc code=end

