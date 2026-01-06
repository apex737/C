class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
class MySLL:
    def __init__(self):
        # C에서는 dummyHead/Tail을 쓰는데 여기는 그냥 포인터처럼 쓸 수있네?
        self.head = None            # None 객체를 계속 밀어내는 삽입 구조
        
    def insert_head(self, key):
        newNode = Node(key)
        newNode.next = self.head    # 기존 헤드는 새로운 헤드 다음으로 밀려난다
        self.head = newNode         # 내가 새로운 헤드
        
    def insert_at_pos(self, key, pos):
        if pos == 0:    
            self.insert_head(key)
        else:
            current = self.head
            newNode = Node(key)
            for _ in range(pos-1):       # (pos-1)번 순회 (prevIdx 찾기)
                if current is None:      # Bound 처리
                    return
                current = current.next  # prevNode에 도달
                
            if current is None: # Ex. {H, None} 구조에서 insert(2) 같은 입력은
                return          # For Bound 처리만으로 잡아낼 수 없음
                                # 이러한 off by one 리스크가 1-ptr(SLL)의 한계
                                  
            newNode.next = current.next
            current.next = newNode
                
            
    def delete(self, key):
        current = self.head
        prev = None                 # None으로 지정한 순간 Null 체크 의무
        while current:
            if current.data == key: # Head를 삭제한다면 어쩔텐가??
                if prev:    
                    prev.next = current.next
                else:                           # Head 삭제 예외처리
                    self.head = current.next    # head 뒷 노드가 head가 됨
            prev = current
            current = current.next
            
    def search(self, key):
        current = self.head
        while current:
            if current.data == key:
                return True, current.data
            current = current.next
        return False, 0
    
    def traverse(self):
        current = self.head
        while current:
            print(current.data, end=' -> ')
            current = current.next
        print(None)
        
mSLL = MySLL()
mSLL.insert_head(1)  
mSLL.insert_head(2)
mSLL.insert_head(3)
mSLL.insert_at_pos(4,4)
mSLL.traverse()