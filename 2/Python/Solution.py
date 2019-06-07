# -*- coding:utf-8 -*-


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def reConstructBinaryTree(self, pre, tin):
        if not len(pre):
            return None
        root = TreeNode(pre[0])
        pos = tin.index(pre[0])
        root.left = self.reConstructBinaryTree(pre[1:1 + pos], tin[:pos])
        root.right = self.reConstructBinaryTree(pre[pos + 1:], tin[pos + 1:])
        return root

    def printAftTree(self, root):
        if (root):
            if (root.left):
                self.printAftTree(root.left)

            if (root.right):
                self.printAftTree(root.right)

            print(root.val, end="")


pre = [1, 2, 4, 7, 3, 5, 6, 8]
tin = [4, 7, 2, 1, 5, 3, 8, 6]

Solution().printAftTree(Solution().reConstructBinaryTree(pre, tin))
