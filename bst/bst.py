class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        
class BST:
    def insert(self, node, val):
        # Leaf에서만 삽입이 일어난다 (branch push back)
        if node is None:
            return Node(val)
        
        if val < node.data:
            node.left = self.insert(node.left, val)
        elif val > node.data:
            node.right = self.insert(node.right, val)
        # 재귀에 의해 branch push back이 루트(Caller)에 반영
        return node
            
    
    def search(self, node, val, depth=0):
        if node is None:
            print("Not Found")
            return None
        
        if node.data == val:
            print(f"Found: {val} | Depth: {depth}")
            return node
        
        if val < node.data:
            # 재귀: 누적 변수를 인자로 넘기면서 갱신
            return self.search(node.left, val, depth+1)
        if val > node.data:
            return self.search(node.right, val, depth+1)
    
    def min_val_node(self, node):
        min_node = node
        # 왼쪽 브랜치가 없으면 오른쪽의 첫번째 반환
        if min_node is not None:
            while min_node.left:
                min_node = min_node.left
        return min_node
        
    def delete(self, node, val):
        # Leaf에서부터 반환
        if node is None:
            return node
        
        if val < node.data:
            node.left = self.delete(node.left, val)
        elif val > node.data:
            node.right = self.delete(node.right, val)
        else: 
            # val == node.data
            # 둘다 None이면 None 반환해서 제거
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            # 자식이 L/R 둘다 있으면 R_minValNode로 대체
            rmnode = self.min_val_node(node.right)
            node.data = rmnode.data
            node.right = self.delete(node.right, rmnode.data)
        
        return node
    
    def inorder(self, node):
        if node:
            self.inorder(node.left)
            print(node.data, end=' ')
            self.inorder(node.right)
            
    def level_order(self, node):
        # 1. 항상 Null Check
        if node is None:
            return
        # root를 받아서
        from collections import deque
        q = deque([node]) # 왜 node아니고 [node]?
        
        while q:
            pos = q.popleft()
            print(pos.data, end=' ')
            # 2. 항상 Null Check
            if pos.left:
                q.append(pos.left)
            if pos.right:
                q.append(pos.right)
        print()
    
    
bst = BST()
root = Node(40)
# depth = 0
vals = [40,50,20,10,30, 50, 50, 60,70,80]
for val in vals:
    bst.insert(root, val)
bst.search(root, 80)
bst.delete(root, 40)
bst.inorder(root)
print()
bst.level_order(root)
