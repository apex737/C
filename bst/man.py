class Node:
    def __init__(self, val):
        self.value = val
        self.left = None
        self.right = None

class BST:
    def insert(self, node, val):
        if not node:
            return Node(val)
        if val < node.value:
            node.left = self.insert(node.left, val)
        elif val > node.value:
            node.right = self.insert(node.right, val)
        return node

    def search(self, node, val):
        if not node or node.value == val:
            return node
        if val < node.value:
            return self.search(node.left, val)
        else:
            return self.search(node.right, val)

    def minValueNode(self, node):
        current = node
        while current.left:
            current = current.left
        return current

    def delete(self, node, val):
        if not node:
            return node
        if val < node.value:
            node.left = self.delete(node.left, val)
        elif val > node.value:
            node.right = self.delete(node.right, val)
        else:
            if not node.left:
                return node.right
            elif not node.right:
                return node.left
            temp = self.minValueNode(node.right)
            node.value = temp.value
            node.right = self.delete(node.right, temp.value)
        return node

    def inorder(self, node):
        if node:
            self.inorder(node.left)
            print(node.value, end=' ')
            self.inorder(node.right)


tree = BST()
root = None
for val in [50, 30, 70, 20, 40, 60, 80]:
    root = tree.insert(root, val)

print("Inorder before deletion:")
tree.inorder(root)  
# 20 30 40 50 60 70 80

root = tree.delete(root, 30)

print("\nInorder after deleting 50:")
tree.inorder(root)  
# 20 40 50 60 70 80

print("\nSearch 70:")
print(tree.search(root, 70).value)
#70