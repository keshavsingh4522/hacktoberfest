class Node:
   def __init__(self, data=None):
      self.data = data
      self.next = None

class LnkdList:
   def __init__(self):
      self.head = None

l1 = LnkdList()
l1.head = Node("Mon")
e2 = Node("Tue")
e3 = Node("Wed")
# Link first Node to second node
l1.head.next = e2
# Link second Node to third node
e2.next = e3
