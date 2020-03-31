#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

'''
class Solution:
    def isSymmetric(self, root):
        if root:
            if root.left and root.right and root.left.val != root.right.val:
                return False
            elif (root.left and not root.right) or (root.right and not root.left):
                return False
            else:
                def check(l, r, f):
                    if not f:
                        return f
                    elif l and r:
                        if l.val == r.val:
                            return check(l.right, r.left, True) and check(l.left, r.right, True)
                        else:
                            return False
                    elif l or r:
                        return False
                    else:
                        return True
                return check(root.left, root.right, True)
        else:
            return True
'''

from collections import deque


class Solution:
    def isSymmetric(self, root):
        if root:
            if root.left and root.right and root.left.val != root.right.val:
                return False
            elif (root.left and not root.right) or (root.right and not root.left):
                return False
            elif root.left == root.right == None:
                return True
            else:
                left = deque([root.left]); right = deque([root.right])
                while left and right:
                    if not left or not right:
                        return False
                    a = left.popleft(); b = right.popleft()
                    if a.val != b.val:
                        return False
                    else:
                        if a.left and b.right and a.left.val == b.right.val:
                            left.append(a.left); right.append(b.right)
                        elif not a.left == b.right == None:
                            return False
                        if a.right and b.left and b.left.val == a.right.val:
                            left.append(a.right); right.append(b.left)
                        elif not a.right == b.left == None:
                            return False
                if left or right:
                    return False
                else:
                    return True
        else:
            return True
        

# @lc code=end

