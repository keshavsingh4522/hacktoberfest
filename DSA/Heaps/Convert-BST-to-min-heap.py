class Node:

    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None


def inorderTraversal(root,arr):
    if root == None:
        return

    inorderTraversal(root.left,arr)
    arr.append(root.data)
    inorderTraversal(root.right,arr)

def BSTToMinHeap(root,arr,i):
    if root == None:
        return

    i[0]+= 1
    root.data = arr[i[0]]
    BSTToMinHeap(root.left,arr,i)
    BSTToMinHeap(root.right,arr,i)

def convertToMinHeapUtil(root):

    arr = []
    i = [-1]
    inorderTraversal(root,arr)
    BSTToMinHeap(root,arr,i)


def preorderTraversal(root):

    if root is None:
        return

    print(root.data, end = " ")

    preorderTraversal(root.left)
    preorderTraversal(root.right)

root = Node(4)
root.left = Node(2)
root.right = Node(6)
root.left.left = Node(1)
root.left.right = Node(3)
root.right.left = Node(5)
root.right.right = Node(7)

convertToMinHeapUtil(root)
print("Preorder Traversal:")
preorderTraversal(root)
