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

class Solution:
    def isSymmetric(self, root):

# @lc code=end

