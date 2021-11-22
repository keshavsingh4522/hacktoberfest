
class Node():
    def __init__(self,cleft,mleft,boat):
        self.cannibal_l=cleft
        self.cannibal_r=3-cleft
        self.missionary_l=mleft
        self.missionary_r=3-mleft
        self.boat=boat
        self.parent_node=None

    def chk_goal(self):
        if self.cannibal_l==0 and self.missionary_l==0:
            return True
        return False

    def chk_valid(self):
        if self.missionary_l>=0 and self.cannibal_r>=0 and self.missionary_l>=0 and self.missionary_r>=0 and (self.missionary_l==0 or self.missionary_l >= self.cannibal_l)  and ( self.missionary_r==0 or self.missionary_r>=self.cannibal_r):
            return True
        else:
            return False

    def __eq__(self,other):
        return (self.missionary_l,self.missionary_r,self.boat,self.cannibal_l,self.cannibal_r) == (other.missionary_l,other.missionary_r,other.boat,other.cannibal_l,other.cannibal_r)

    def __repr__(self):
        return "(" + str(self.missionary_l) +","+str(self.cannibal_l) + ","+ self.boat + ")"
    def __str__(self):
        path = []
        path.append(self)
        parent = self.parent_node
        while parent:
            path.append(parent)
            parent = parent.parent_node
        for t in path[::-1]:
            print("(" + str(t.missionary_l) +","+str(t.cannibal_l) + ","+ t.boat + ")")
        return ''
    def __hash__(self):
        return hash((self.cannibal_l, self.missionary_l, self.boat, self.cannibal_r, self.missionary_r))
        
        
    
def successors(cur_state):
    children=[]
    if cur_state.boat=='L':
        #One Missionary One Cannibal Move Right   
        if cur_state.cannibal_l>=1 and cur_state.missionary_l>=1:
            new_node=Node(cur_state.cannibal_l-1,cur_state.missionary_l-1,'R')
            if new_node.chk_valid():
                new_node.parent_node=cur_state
                children.append(new_node)
        #Two Missionaries Move Left to Right
        if cur_state.missionary_l>=2:
            new_node=Node(cur_state.cannibal_l,cur_state.missionary_l-2,'R')
            if new_node.chk_valid():
                new_node.parent_node=cur_state
                children.append(new_node)
        
        #Two Cannibals move right    
        if cur_state.cannibal_l>=2:
            new_node=Node(cur_state.cannibal_l-2,cur_state.missionary_l,'R')
            if new_node.chk_valid():
                new_node.parent_node=cur_state
                children.append(new_node)
        
        

        #One Missionary Move Right   
        if cur_state.missionary_l>=1:
            new_node=Node(cur_state.cannibal_l,cur_state.missionary_l-1,'R')
            if new_node.chk_valid():
                new_node.parent_node=cur_state
                children.append(new_node)
        
        #One Cannibal Move Right   
        if cur_state.cannibal_l>=1:
            new_node=Node(cur_state.cannibal_l-1,cur_state.missionary_l,'R')
            if new_node.chk_valid():
                new_node.parent_node=cur_state
                children.append(new_node)
        
    else:
        #Two Missionaries Move R to L
        if cur_state.missionary_r>=2:
            new_node=Node(cur_state.cannibal_l,cur_state.missionary_l+2,'L')
            if new_node.chk_valid():
                new_node.parent_node=cur_state
                children.append(new_node)
        #Two Cannibals move left    
        if cur_state.cannibal_r>=2:
            new_node=Node(cur_state.cannibal_l+2,cur_state.missionary_l,'L')
            if new_node.chk_valid():
                new_node.parent_node=cur_state
                children.append(new_node)
        
        #One Missionary One Cannibal Move Left   
        if cur_state.cannibal_r>=1 and cur_state.missionary_r>=1:
            new_node=Node(cur_state.cannibal_l+1,cur_state.missionary_l+1,'L')
            if new_node.chk_valid():
                new_node.parent_node=cur_state
                children.append(new_node)

        #One Missionary Move Left   
        if cur_state.missionary_r>=1:
            new_node=Node(cur_state.cannibal_l,cur_state.missionary_l+1,'L')
            if new_node.chk_valid():
                new_node.parent_node=cur_state
                children.append(new_node)
        
        #One Cannibal Move Right   
        if cur_state.cannibal_r>=1:
            new_node=Node(cur_state.cannibal_l+1,cur_state.missionary_l,'L')
            if new_node.chk_valid():
                new_node.parent_node=cur_state
                children.append(new_node)
            
    return children

def BFS():
    initial_node=Node(3,3,'L')
    if initial_node.chk_goal():
        return initial_node
    queue=list()
    visited=set()
    queue.append(initial_node)
    while queue:
        cur_node=queue.pop(0)
        if cur_node.chk_goal():
            return cur_node
        visited.add(cur_node)
        children=successors(cur_node)
        for child in children:
            if child not in visited and child not in queue:
                queue.append(child)
    return None
        
def print_solution(solution):
    path = []
    path.append(solution)
    parent = solution.parent_node
    while parent:
        path.append(parent)
        parent = parent.parent_node
        for t in range(len(path)):
            state = path[len(path) - t - 1]
            print("(" + str(state.cannibal_l) + "," + str(state.missionary_l) + "," + state.boat + "," + str(state.cannibal_r) + "," + str(state.missionary_r) + ")")


if __name__=='__main__':
    solution=BFS()
    print("MISSIONARIES and CANNIBALS")
    print("Format of Answer (m,c,b) where m is count of missionaries , c is count of cannibals and b is the position of boat")
    print(solution)
