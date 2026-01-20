class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            return None  # Return None if the stack is empty

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        else:
            return None  # Return None if the stack is empty

    def size(self):
        return len(self.items)

# Example usage
stack = Stack()

stack.push(1)
stack.push(2)
stack.push(3)

print("Stack:", stack.items)  # Output: Stack: [1, 2, 3]
print("Size of the stack:", stack.size())  # Output: Size of the stack: 3
print("Top element:", stack.peek())  # Output: Top element: 3

popped_item = stack.pop()
print("Popped item:", popped_item)  # Output: Popped item: 3
print("Stack after popping:", stack.items)  # Output: Stack after popping: [1, 2]
