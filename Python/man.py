class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_at_head(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def insert_at_tail(self, data):
        new_node = Node(data)
        if not self.tail:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node

    def delete_from_head(self):
        if not self.head:
            return
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None

    def delete_from_tail(self):
        if not self.tail:
            return
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None

    def search_from_head(self, key):
        current = self.head
        while current:
            if current.data == key:
                return True
            current = current.next
        return False

    def search_from_tail(self, key):
        current = self.tail
        while current:
            if current.data == key:
                return True
            current = current.prev
        return False

    def traverse_forward(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

    def traverse_backward(self):
        current = self.tail
        while current:
            print(current.data, end=" <- ")
            current = current.prev
        print("None")

dll = DoublyLinkedList()

dll.insert_at_head(14)
dll.insert_at_head(36)
dll.insert_at_head(61)
dll.insert_at_head(77)
dll.insert_at_head(22)

dll.insert_at_tail(48)

dll.delete_from_tail()

print(dll.search_from_tail(36)) # True

dll.traverse_forward()
# 22 -> 77 -> 61 -> 36 -> 14 -> None

dll.traverse_backward()
# 14 <- 36 <- 61 <- 77 <- 22 <- None