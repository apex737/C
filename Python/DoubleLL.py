# insertHead/Tail
# popHead/Tail 
# searchHead/Tail
# traversHead/Tail

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoubleLL:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def insert_head(self, data):
        # C의 더미 H/T와 달리, H/T를 대체하는 방식
        newNode = Node(data)
        if self.head is None:  
            # 핵심: 노드가 1개일 때 H/T가 동일 노드
            self.head = self.tail = newNode
        else:
            old_head = self.head
            self.head = newNode
            newNode.next = old_head
            old_head.prev = newNode
            
    def insert_tail(self, data):
        newNode = Node(data)
        if self.tail is None:  
            # H/T가 동일 노드
            self.head = self.tail = newNode
        else:
            old_tail = self.tail
            self.tail = newNode
            newNode.prev = old_tail
            old_tail.next = newNode
            
    def pop_head(self):
        if self.head is None:
            return None
        else:
            ret = self.head.data
            if self.head == self.tail:
                # 노드가 1개
                self.head = self.tail = None
            else:
                old_head = self.head
                self.head = old_head.next
                # Q. self.head 연결만 끊어주면 GC가 처리할까??
                # A. 중요한건 방향이다. 나를 가리키는 누군가가 없으면
                #    내가 누군가를 가리켜도 GC가 죽이러 온다.
                # old_head.next = None (Dead Code)
                self.head.prev = None
            
            return ret
            
            
    def pop_tail(self):
        if self.tail is None:
            return
        else:
            ret = self.tail.data
            if self.head == self.tail:
                # 노드가 1개
                self.head = self.tail = None
            else:
                old_tail = self.tail
                self.tail = old_tail.prev
                self.tail.next = None
            
            return ret
            
    def search_from_head(self, data):
        if self.head is None:
            return None
        else:
            current = self.head
            while current:
                if current.data == data:
                    return True
                current = current.next
            return False
    
    def traverse_from_tail(self):
        if self.tail is None:
            return
        else:
            current = self.tail
            while current:
                print(current.data, end=' -> ')
                current = current.prev
            print('None')
    
    def traverse_from_head(self):
        if self.head is None:
            return
        else:
            current = self.head
            while current:
                print(current.data, end=' -> ')
                current = current.next
            print('None')
    
print('test-start')
print()
dll = DoubleLL()
for i in range(5):
    dll.insert_head(i)
for i in range(5,10):
    dll.insert_tail(i)

dll.traverse_from_head()
print(dll.pop_head())
print(dll.pop_tail())
dll.traverse_from_head()