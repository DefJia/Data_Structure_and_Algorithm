#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        new = ListNode(0)
        cur = new
        flag, tmp = 0, 0
        while l1 and l2:
            tmp += flag
            flag = 0
            if (l1.val + l2.val) >= 10:
                flag = 1
                tmp += l1.val + l2.val - 10
            else:
                tmp += l1.val + l2.val
            q = ListNode(tmp)
            tmp = 0
            cur.next = q
            cur = q
            l1 = l1.next
            l2 = l2.next
        if l1 or l2:
            w = l1 if l1 else l2
            w.val += flag
            cur.next = w
        elif flag:
            q = ListNode(flag)
            cur.next = q
            cur = q
        return new.next



if __name__ == "__main__":
    l1 = ListNode(3)
    l1.next = ListNode(1)
    l2 = ListNode(4)
    l2.next = ListNode(8)
    q = Solution().addTwoNumbers(l1, l2)
    while q:
        print(q.val)
        q = q.next


# @lc code=end

