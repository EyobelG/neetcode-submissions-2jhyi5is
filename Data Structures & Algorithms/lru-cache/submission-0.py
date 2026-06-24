class Node:
    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}

        self.left = Node(0, 0)
        self.right = Node(0, 0)
        self.left.next = self.right
        self.right.prev = self.left     

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            
            self.remove(node)
            self.insert(node)
            return node.val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        new_node = Node(key, value)
        self.cache[key] = new_node
        self.insert(new_node)

        if len(self.cache) > self.capacity:
            lru_node = self.left.next
            self.remove(lru_node)
            del self.cache[lru_node.key]
    
    def insert(self, node: Node) -> None:
        # Get the node currently right before the right dummy node
        prev_node = self.right.prev
        
        # Wire up the new node between prev_node and self.right
        prev_node.next = node
        self.right.prev = node
        
        node.prev = prev_node
        node.next = self.right
    
    def remove(self, node: Node) -> None:
        # Get the nodes before and after this one
        prev_node = node.prev
        next_node = node.next
        
        # Make them point directly to each other, skipping 'node'
        prev_node.next = next_node
        next_node.prev = prev_node
        


