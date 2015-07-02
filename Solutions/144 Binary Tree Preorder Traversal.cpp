# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        curans = []
        stack = [root]
        
        while stack:
            node = stack.pop()
            if node:
                curans.append(node.val)
                stack.append(node.right)
                stack.append(node.left)

        return curans