class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        
class BST:
    def insert(self, node, data):
        # leaf에 도착
        if node is None:
            return Node(data)
        
        if data < node.data:
            node.left = self.insert(node.left, data)
        if data > node.data:
            node.right = self.insert(node.right, data)
        
        # 값이 같으면?
        return node
    
    def search(self, node, data, depth = 0):
        if node is None:
            print("None")
            return None

        if data < node.data:
            return self.search(node.left, data, depth+1)
        elif data > node.data:
            return self.search(node.right, data, depth+1)
        else:
            print(f"FOUND {data} | DEPTH: {depth}")
            return node
    
    def minValNode(self, node):
        if node is None:
            return None
        pos = node
        while pos.left:
            pos = pos.left
        return pos
    
    def delete(self, node, data, depth=0):
        if node is None:
            return None
        
        if data < node.data:
            node.left = self.delete(node.left, data, depth+1)
        elif data > node.data:
            node.right = self.delete(node.right, data, depth+1)
        else:
            # 지울 노드 L/R에 자식이 하나 이하; replace root
            if node.left is None:
                print(f"DELETE: {data} | DEPTH: {depth}")
                return node.right
            elif node.right is None:
                print(f"DELETE: {data} | DEPTH: {depth}")
                return node.left
            else:
                # 지울 노드 L/R 모두에 자식이 존재
                # 지울 노드 우측에서 minValNode를 찾기 위해 탐색 Depth가 더 깊어짐
                rmnode = self.minValNode(node.right)
                print(f"Replacing value {node.data} with {rmnode.data}")
                node.data = rmnode.data
                # 우측 서브트리에서 중복된 값을 가진 노드를 제거
                node.right = self.delete(node.right, node.data, depth+1)
        return node
    
    def inorder(self, node):
        if node:
            self.inorder(node.left)
            print(node.data, end=' ')
            self.inorder(node.right)
    
    def levelOrder(self, node):
        # 덱을 popLeft하면서 L,R를 추가한다
        from collections import deque
        q = deque([node])
        while q:
            root = q.popleft()
            print(root.data, end=' ')
            if root.left:
                q.append(root.left)
            if root.right:
                q.append(root.right)
        print()

bst = BST()
root = Node(40)
# depth = 0
vals = [40,50,20,10,30,  45, 60,70,80]
for val in vals:
    bst.insert(root, val)

bst.inorder(root)
print()
print(bst.minValNode(root).data)
bst.search(root, 70)
bst.levelOrder(root)
bst.delete(root, 50)
bst.levelOrder(root)
