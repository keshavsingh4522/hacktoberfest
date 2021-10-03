def area(x1, y1, x2, y2, x3, y3):
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2.0)

def isInside(x1, y1, x2, y2, x3, y3, x, y):

    A = area(x1, y1, x2, y2, x3, y3)

    A1 = area(x, y, x2, y2, x3, y3)

    A2 = area(x1, y1, x, y, x3, y3)

    A3 = area(x1, y1, x2, y2, x, y)

    if (A == A1 + A2 + A3):
        return True
    else:
        return False

# Driver program
if (isInside(0, 0, 20, 0, 10, 30, 10, 15)):
    print('Inside')
else:
    print('Not Inside')