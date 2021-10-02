class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x , y = 0,0
        left = 0
        directn = 0
        instructions = instructions *4
        moves = [[0,1], [-1,0], [0,-1], [1,0]]
        for i in instructions:
            if i == 'G':
                x += moves[directn][0]
                y +=moves[directn][1]
            elif i == 'L':
                directn = (directn+1) %4
            elif i == 'R':
                directn = (directn+3) %4
        if (x == 0 and y == 0):
            return True

        return False
            

class Solution(object):
    def isRobotBounded(self, instructions):
        directions = [[0,1],[1,0],[0,-1],[-1,0]]
        x = y = 0
        idx = 0
        
        for i in instructions:
            if i == 'L':
                idx = (idx +3)%4
            elif i == 'R':
                idx = (idx +1) %4
            else:
                x += directions[idx][0]
                y += directions[idx][1]
        return (x == 0 and y == 0) or idx != 0
