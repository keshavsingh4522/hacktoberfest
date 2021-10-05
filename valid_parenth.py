class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack=[]
        pairs= {'[':']','(':')','{':'}'}
        for c in s:
            if c in pairs:
                stack.append(pairs[c])
            else:
                if len(stack)==0 or stack.pop()!=c:
                        return False
                     
        return len(stack)==0