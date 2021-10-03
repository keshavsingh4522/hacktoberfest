class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def doOverlap(l1, r1, l2, r2):
    # check if rectangle is actually a line
    if (l1.x == r1.x or l1.y == r1.y or l2.x == r2.x or l2.y == r2.y):
        # the line cannot have positive overlap
        return False

    # if one rect. is on left side of other
    if (l1.x >= r2.x or l2.x >= r1.x):
        return False

    # if one rectangle is above other either
    if (r1.y >= l2.y or r2.y >= l1.y):
        return False
    
    return True

# Driver Code
if __name__ == "__main__":
    l1 = Point(0, 10)
    r1 = Point(10, 0)
    if l1.y < r1.y:
        l1.y, r1.y = r1.y, l1.y
        
    l2 = Point(5,5)
    r2 = Point(15, 0)
    if l2.y < r2.y:
        l2.y, r2.y = r2.y, l2.y
        

    if doOverlap(l1, r1, l2, r2):
        print("Rectangles Overlap")
    else:
        print("Rectangles Don't Overlap")