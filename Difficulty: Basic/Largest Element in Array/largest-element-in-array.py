class Solution:
    def largest(self, arr):
        maxEle = float('-inf')
        
        for i in arr:
            if i > maxEle:
                maxEle = i
        
        return maxEle
        
