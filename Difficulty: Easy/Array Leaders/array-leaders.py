class Solution:
    def leaders(self, arr):
        n = len(arr)
        
        nge = [-1] * n
        res = []
        
        stack = []
        
        for i in range(len(arr)-1, -1, -1):
            while len(stack) != 0 and arr[i] >= stack[-1]:
                stack.pop()
        
            if len(stack) == 0:
                nge[i] = -1
            else:
                nge[i] = stack[-1]
            
            stack.append(arr[i])
                
        
        for i in range(len(nge)):
            if nge[i] == -1:
                res.append(arr[i])
                
        return res