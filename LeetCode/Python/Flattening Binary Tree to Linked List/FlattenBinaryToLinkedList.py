class Solution(object):
    # stack definition
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        if root is None:
            return
        if root.left is None and root.right is None:
            return
        current = root
        stack = [root]
        while stack:
            node = stack.pop()
            self.appendNode(stack, node.right)
            self.appendNode(stack, node.left)
            if current != node:
                current.right = node
                current.left = None
                current = node

    def appendNode(self, stack, node):
        if node:
            stack.append(node)