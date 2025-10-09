class Solution:
    def factorial(self, N):
        fact = 1
        while(N>=1):
            fact = fact * N
            N = N-1
      
        return str(fact)

      
if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ans = ob.factorial(N)
        for i in ans:
            print(i,end="")
        print()


       
# Input: N = 10
# Output: 3628800
# Explanation :
# 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
