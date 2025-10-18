class Solution:    
    def findUnion(self, a, b):
        i = 0
        j = 0
        
        a.sort()
        b.sort()
        
        union = []
        
        while i < len(a) and j < len(b):
            if a[i] <= b[j]:
                if len(union) == 0 or union[-1] != a[i]:
                    union.append(a[i])
                i+=1
            else:
                if len(union) == 0 or union[-1] != b[j]:
                    union.append(b[j])
                j+=1
                
        while i < len(a):
            if len(union) == 0 or union[-1] != a[i]:
                union.append(a[i])
            i += 1
            
        while j < len(b):
            if len(union) == 0 or union[-1] != b[j]:
                union.append(b[j])
            j += 1
        
        return union