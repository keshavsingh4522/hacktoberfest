

class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        if value < self.value:
            if self.left is None:
                self.left = BST(value)
            else:
                self.left.insert(value)
        else:
            if self.right is None:
                self.right = BST(value)
            else:
                self.right.insert(value)
        return self


def findClosestValueInBst(tree, target):
    return findClosestValueInBstHelper(tree, target, float("inf"))

# Solution 1 starts here
# Avarage: O(log(n)) time | O(log(n)) space
# Worst: O(n) time | O(n) space
def findClosestValueInBstHelper(tree, target, closest):
    if tree is None:
        return closest
    if abs(target - closest) > abs(tree.value - target):
        closest = tree.value
    if target < tree.value:
        return findClosestValueInBstHelper(tree.left, target, closest)
    elif target > tree.value:
        return findClosestValueInBstHelper(tree.right, target, closest)
    else:
        return closest
# Solution 1 ends here

# Solution 2 starts here
# Avarage: O(log(n)) time | O(1) space
# Worst: O(n) time | O() space
def findClosestValueInBstHelper_2(tree, target, closest):
    current_node = tree
    while current_node is not None:
        if abs(target - closest) > abs(target - current_node.value):
            closest = current_node.value
        if target < current_node.value:
            current_node = current_node.left
        elif target > current_node.value:
            current_node = current_node.right
        else:
            break
    return closest
# Solution 2 ends here


test_tree = BST(100).insert(5).insert(15).insert(5).insert(2).insert(1).insert(22) \
        .insert(1).insert(1).insert(3).insert(1).insert(1).insert(502).insert(55000) \
        .insert(204).insert(205).insert(207).insert(206).insert(208).insert(203) \
        .insert(-51).insert(-403).insert(1001).insert(57).insert(60).insert(4500)


closest_val = findClosestValueInBst(test_tree, 200)
print(str(closest_val) + " is the Closest Value")
